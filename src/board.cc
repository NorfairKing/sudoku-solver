#include <iostream>
#include <vector>
#include <queue>
#include "option.h"
#include "board.h"
#include "index.h"

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

short Board::getTileFromBox(int box, int i) {
  int blockRow = box / BLOCK_SIZE;
  int blockCol = box % BLOCK_SIZE;
  int rowInBlock = i / BLOCK_SIZE;
  int colInBlock = i % BLOCK_SIZE;
  return getTile(blockRow * BLOCK_SIZE + rowInBlock, blockCol * BLOCK_SIZE + colInBlock);
}

void Board::setTile(int x, int y, short n) {
  tile[x][y] = n;
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
    sum += 1 << (getTileFromBox(b, i) - 1);
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
    possibilities[getTileFromBox(box, i)] = false;
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
