#include <iostream>
#include "board.h"

Board::Board() {
  for (int x; x < SIZE; ++x) {
    for (int y; y < SIZE; ++y) {
      tile[x][y] = 0;
    }
  }
}

Board::~Board() {}

short Board::getTile(int x, int y) {
  return tile[x][y];
}

void Board::setTile(int x, int y, short n) {
  tile[x][y] = n;
}


std::istream& operator>>(std::istream &in, Board &board) {
  char buf;
  for (int x = 0; x < SIZE; ++x) {
    for (int y = 0; y < SIZE; ++y) {
      in.get(buf);
      board.setTile(x, y, buf - '0');
    }
    in.get();
  }
  
  return in;
}

std::ostream& operator<<(std::ostream &out, Board &board)
{
  for (int x = 0; x < SIZE; ++x) {
    for (int y = 0; y < SIZE; ++y) {
      out << board.getTile(x, y);
    }
    out << std::endl;
  }

  return out;
}
