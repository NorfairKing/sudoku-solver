#ifndef board_h__
#define board_h__

const int SIZE = 9;

class Board {
  private:
    short tile[SIZE][SIZE];
  public:
    Board();
    ~Board(); 
    short getTile(int x, int y);
    void setTile(int x, int y, short n);
};

#endif
