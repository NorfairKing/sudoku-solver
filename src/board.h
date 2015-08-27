#ifndef board_h__
#define board_h__

const int SIZE = 9;

class Board {
  private:
    short tile[SIZE][SIZE];
    bool checkRow(int r);
    bool checkColumn(int c);
    bool checkBox(int b);
  public:
    Board();
    ~Board(); 
    short getTile(int x, int y);
    void setTile(int x, int y, short n);
    bool isSolved();
    friend std::ostream& operator<< (std::ostream &out, Board &board);
    friend std::istream& operator>> (std::istream &in, Board &board);
};

#endif
