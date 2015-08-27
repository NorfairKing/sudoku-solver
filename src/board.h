#ifndef board_h__
#define board_h__

#include "option.h"
#include "constants.h"

class Board {
  private:
    short tile[SIZE * SIZE];
    bool checkRow(int r);
    bool checkColumn(int c);
    bool checkBox(int b);
    option getOption(int r, int x);
  public:
    Board();
    ~Board(); 
    short getTile(int ix);
    short getTile(int r, int c);
    short getTileByBox(int r, int c);
    void setTile(int ix, short n);
    void setTile(int r, int c, short n);
    bool isSolved();
    void solve();
    friend std::ostream& operator << (std::ostream& out, Board& board);
    friend std::istream& operator >> (std::istream& in, Board& board);
};

#endif
