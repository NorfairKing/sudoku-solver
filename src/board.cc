#include "board.h"

Board::Board() {
  for (int x; x < SIZE; ++x) {
    for (int y; y < SIZE; ++y) {
      tile[x][y] = 0;
    }
  }
}

Board::~Board() {
}
short Board::getTile(int x, int y) {
  return tile[x][y];
}
void Board::setTile(int x, int y, short n) {
  tile[x][y] = n;
}
