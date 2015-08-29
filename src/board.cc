#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include "option.h"
#include "board.h"
#include "index.h"

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
  // If the board is already solved, we're done.
  if (isSolved()) { return; }

  // Whether any option has been found
  bool foundAny = false;

  // The current best option (least amount of possibilities to fill the tile) found.
  option bestOption;
  bestOption.row = -1; bestOption.col = -1; // Just so it's initialised.
  bestOption.nr_options = INT_MAX; // High so any option is better

  // Search first, act later.
  for (int r = 0; r < SIZE; ++r) {
    for (int c = 0; c < SIZE; ++c) {

      // If the tile is not empty, don't consider it.
      if (getTile(r,c) != 0) { continue; }

      // Calculate the options for this tile.
      option o = getOption(r, c);

      // If the number of options is 0, something went wrong and this board is not solvable.
      if (o.nr_options == 0) { return; }

      // The nuber of options is non-zero, so we found an option.
      foundAny = true;

      // We've found an option that we should definitely explore
      if (o.nr_options == 1) {
        bestOption = o;
        break;
      }

      // If this option is better, set it as the new best option.
      if (o.nr_options < bestOption.nr_options) {
        bestOption = o;
      }
    }
  }

  if (foundAny) {
    // Go over all possibilities, fill each one in and solve recursively untill
    // a solution is found.
    for (int i = 1; i <= SIZE; ++i) {
      if (!bestOption.options[i]) { continue; }
      Board b = *this; // copy
      b.setTile(bestOption.row, bestOption.col, i);
      b.solve();
      if (b.isSolved()) {
        *this = b; // copy back
        break;
      }
    }
    // Still found nothing, this is not solveable.
    return;
  } else {
    // If there were no options found there and the sudoku wasn't solved already,
    // there is no way to solve it.
    return;
  }
  solve();
}

option Board::getOption(int r, int c) {
  option o;
  o.row = r;
  o.col = c;

  // Initialize all but 0 to true.
  o.options[0] = false;
  for (int i = 1; i <= SIZE; ++i) { o.options[i] = true; }

  // Scratch off every number that's not possible.
  scratchRow(o.options, r, c);
  scratchColumn(o.options, r, c);
  scratchBox(o.options, r, c);

  // Cache nr of possibilities.
  o.nr_options = 0;
  for (int i = 0; i <= SIZE; ++i) {
    if (o.options[i]) { ++o.nr_options; }
  }

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

bool Board::isSolved() {
  bool solved = true;
  for (int i = 0; i < SIZE; ++i) {
    solved = checkRow(i) && checkColumn(i) && checkBox(i);
    if (!solved) { return false; }
  }
  return true;
}

void initCheck(bool possibilities[SIZE+1]) {
  possibilities[0] = true;
  for (int i = 1; i <= SIZE; ++i) { possibilities[i] = false; }
}

bool checkAllTrue(bool possibilities[SIZE+1]) {
  for (int i = 0; i <= SIZE; ++i) {
    if (!possibilities[i]) { return false; }
  }
  return true;
}

bool Board::checkRow(int r) {
  bool possibilities[SIZE+1];
  initCheck(possibilities);
  for (int c = 0; c < SIZE; ++c) {
    possibilities[getTile(r,c)] = true;
  }
  return checkAllTrue(possibilities);
}
bool Board::checkColumn(int c) {
  bool possibilities[SIZE+1];
  initCheck(possibilities);
  for (int r = 0; r < SIZE; ++r) {
    possibilities[getTile(r,c)] = true;
  }
  return checkAllTrue(possibilities);
}
bool Board::checkBox(int b) {
  bool possibilities[SIZE+1];
  initCheck(possibilities);
  for (int i = 0; i < SIZE; ++i) {
    possibilities[getTileByBox(b,i)] = true;
  }
  return checkAllTrue(possibilities);
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

  if (board.isSolved()) {
    out << "Solved";
  } else {
    out << "Not solved";
  }

  out << std::endl;
  return out;
}
