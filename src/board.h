#ifndef board_h__
#define board_h__

#include "option.h"
#include "constants.h"

class Board {
  private:
    int tile[SIZE * SIZE];
    option getOption(int r, int x);
    void scratchRow(bool possibilities[SIZE + 1], int r, int c);
    void scratchColumn(bool possibilities[SIZE + 1], int r, int c);
    void scratchBox(bool possibilities[SIZE + 1], int r, int c);
    void fillOption(option o);
    bool checkRow(int r);
    bool checkColumn(int r);
    bool checkBox(int r);
  public:
    Board();
    ~Board(); 
    int getTile(int ix);
    int getTile(int r, int c);
    int getTileByBox(int r, int c);
    void setTile(int ix, int n);
    void setTile(int r, int c, int n);
    void solve();
    bool isSolved();
    friend std::ostream& operator << (std::ostream& out, Board& board);
    friend std::istream& operator >> (std::istream& in, Board& board);
};

#endif
