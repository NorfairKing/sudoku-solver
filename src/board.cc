#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <climits>
#include "option.h"
#include "board.h"
#include "index.h"

Board::Board() {
  for (int x; x < SIZE*SIZE; ++x) {
    tile[x] = 0;
  }
}

Board::~Board() {}

int Board::getTile(int ix) {
  return tile[ix];
}

int Board::getTile(int r, int c) {
  return getTile(index(r,c));
}

int Board::getTileByBox(int box, int i) {
  return getTile(indexByBox(box, i));
}

void Board::setTile(int ix, int n) {
  tile[ix] = n;
}

void Board::setTile(int r, int c, int n) {
  setTile(index(r,c), n);
}

void Board::solve() {
  bool found = false;
  option bestOption;
  bestOption.nr_options = INT_MAX;
  for (int r = 0; r < SIZE; ++r) {
    for (int c = 0; c < SIZE; ++c) {
      if (getTile(r,c) != 0) { continue; }
      found = true;
      option o = getOption(r, c);
      if (o.nr_options <= 1) {
        bestOption = o;
        break;
      }
      if (o.nr_options < bestOption.nr_options) {
        bestOption = o;
      }
    }
  }
  // Solved.
  if (!found) { return ;}

  // Fill in next option and solve further.
  fillOption(bestOption);
  solve();
}

void Board:: fillOption(option o) {
  setTile(o.row, o.col, o.default_option);
}

option Board::getOption(int r, int c) {
  bool possibilities[SIZE + 1];

  // Initialize all but 0 to true.
  possibilities[0] = false;
  for (int i = 1; i <= SIZE; ++i) { possibilities[i] = true; }

  scratchRow(possibilities, r, c);
  scratchColumn(possibilities, r, c);
  scratchBox(possibilities, r, c);

  int nr_poss = 0;
  for (int i = 1; i <= SIZE; ++i) {
    if (possibilities[i]) { ++nr_poss; }
  }

  int def = 1;
  for (int i = 1; i <= SIZE; i++) {
    if (possibilities[i]) {
      def = i;
      break;
    }
  }

  option o;
  o.row = r;
  o.col = c;
  o.nr_options = nr_poss;
  o.default_option = def;

  return o;
}

void Board::scratchRow(bool possibilities[SIZE + 1], int r, int c) {
  // Check row
  for (int i = 0; i < SIZE; i++) {
    if (i == c) { continue; }
    // If tile (r,i) is set then (r,c) cannot be the same
    // so we scratch that possiblility off the list.
    possibilities[getTile(r, i)] = false;
  }
}

void Board::scratchColumn(bool possibilities[SIZE + 1], int r, int c) {
  for (int i = 0; i < SIZE; i++) {
    if (i == r) { continue; }
    // If tile (i,c) is set then (r,c) cannot be the same
    // so we scratch that possiblility off the list.
    possibilities[getTile(i, c)] = false;
  }
}

void Board::scratchBox(bool possibilities[SIZE + 1], int r, int c) {
  int box = boxIndex(r,c);
  for (int i = 0; i < SIZE; ++i) {
    // i is the index in the box.
    if (i == indexInBox(r, c)) { continue; }
    possibilities[getTileByBox(box, i)] = false;
  }
}

std::istream& operator >> (std::istream &in, Board &board) {
  int buf;
  for (int x = 0; x < SIZE; ++x) {
    for (int y = 0; y < SIZE; ++y) {
      in >> buf;
      board.setTile(x, y, buf);
    }
    in.get(); // Get newline
  }
  
  return in;
}

std::ostream& operator << (std::ostream &out, Board &board)
{
  int width = ceil(log10(SIZE));
  int totalWidth = (width+1)*SIZE + 2*BLOCK_SIZE + 1;
  out << std::endl;
  out << " ";
  for (int x = 0; x < (width+1)*SIZE + 2*BLOCK_SIZE + 1; ++x) {
    out << "-";
  }
  out << " ";
  out << std::endl;


  for (int x = 0; x < SIZE; ++x) {
    out << " | ";
    for (int y = 0; y < SIZE; ++y) {
      out << std::setfill(' ') << std::setw(width) << board.getTile(x, y);
      if (y % BLOCK_SIZE == BLOCK_SIZE - 1) {
        out << " | ";
      } else {
        out << " ";
      }
    }
    if (x % BLOCK_SIZE  == BLOCK_SIZE - 1) {
      out << std::endl;
      out << " ";
      for (int x = 0; x < totalWidth; ++x) {
        out << "-";
      }
      out << " ";
    }
    out << std::endl;
  }

  out << std::endl;
  return out;
}
