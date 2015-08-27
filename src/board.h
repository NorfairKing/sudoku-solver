#ifndef board_h__
#define board_h__

#include "option.h"
#include "constants.h"

class Board {
  private:
    short tile[SIZE][SIZE];
    bool checkRow(int r);
    bool checkColumn(int c);
    bool checkBox(int b);
    option getOption(int r, int x);
  public:
    Board();
    ~Board(); 
    short getTile(int x, int y);
    short getTileFromBox(int box, int ix);
    void setTile(int x, int y, short n);
    bool isSolved();
    void solve();
    friend std::ostream& operator << (std::ostream& out, Board& board);
    friend std::istream& operator >> (std::istream& in, Board& board);
};

#endif
