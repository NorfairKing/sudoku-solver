#include <iostream>
#include <vector>
#include <queue>
#include "option.h"
#include "board.h"
#include "index.h"

Board::Board() {
  for (int x; x < SIZE*SIZE; ++x) {
    tile[x] = 0;
  }
}

Board::~Board() {}

short Board::getTile(int ix) {
  return tile[ix];
}

short Board::getTile(int r, int c) {
  return getTile(index(r,c));
}

short Board::getTileByBox(int box, int i) {
  return getTile(indexByBox(box, i));
}

void Board::setTile(int ix, short n) {
  tile[ix] = n;
}

void Board::setTile(int r, int c, short n) {
  setTile(index(r,c), n);
}

// http://math.stackexchange.com/questions/157682/does-a-solved-sudoku-game-always-have-same-sum-is-this-sum-unique-to-solved-gam
bool Board::isSolved() {
  bool b;
  for (int i = 0; i < SIZE; ++i) {
    b = checkRow(i) && checkColumn(i) && checkBox(i);
    if (!b) {
      return false;
    }
  }
  return true;
}

bool Board::checkRow(int r) {
  short sum = 0;
  for (int i = 0; i < SIZE; ++i) {
    sum += 1 << (getTile(r, i) - 1);
  }
  return sum == BLOCK_SUM;
}

bool Board::checkColumn(int c) {
  short sum = 0;
  for (int i = 0; i < SIZE; ++i) {
    sum += 1 << (getTile(i, c) - 1);
  }
  return sum == BLOCK_SUM;
}

bool Board::checkBox(int b) {
  short sum = 0;
  for (int i = 0; i < SIZE; ++i) {
    sum += 1 << (getTileByBox(b, i) - 1);
  }
  return sum == BLOCK_SUM;
}

void Board::solve() {
  std::priority_queue<option, std::vector<option> > options;

  for (int x = 0; x < SIZE; ++x) {
    for (int y = 0; y < SIZE; ++y) {
      
    }
  }

}

option Board::getOption(int r, int c) {
  bool possibilities[SIZE + 1];

  // Initialize all but 0 to true.
  possibilities[0] = false;
  for (int i; i < SIZE; ++i) { possibilities[i] = true; }

  // Check row
  for (int i; i < SIZE && i != c; i++) {
    // If tile (r,i) is set then (r,c) cannot be the same
    // so we scratch that possiblility off the list.
    possibilities[getTile(r, i)] = false;
  }

  for (int i; i < SIZE && i != r; i++) {
    // If tile (i,c) is set then (r,c) cannot be the same
    // so we scratch that possiblility off the list.
    possibilities[getTile(i, c)] = false;
  }

  int box = boxIndex(r,c);
  for (int i; i < SIZE && i != indexInBox(r,c); ++i) {
    possibilities[getTileByBox(box, i)] = false;
  }

  int nr_poss = 0;
  for (int i = 1; i < SIZE + 1; ++i) {
    if (possibilities[i]) { ++nr_poss; }
  }

  int def = 0;
  int i = 1;
  while (! possibilities[i]) { ++i; }
  def = i;

  option o;
  o.row = r;
  o.col = c;
  o.nr_options = nr_poss;
  o.default_option = def;

  return o;
}

std::istream& operator >> (std::istream &in, Board &board) {
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

std::ostream& operator << (std::ostream &out, Board &board)
{
  for (int x = 0; x < SIZE; ++x) {
    for (int y = 0; y < SIZE; ++y) {
      out << board.getTile(x, y);
    }
    out << std::endl;
  }

  return out;
}
