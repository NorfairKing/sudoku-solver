#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <climits>
#include "option.h"
#include "board.h"
#include "index.h"

Board::Board() {
  for (int x = 0; x < SIZE*SIZE; ++x) {
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
  // If the board is already solved, we're done.
  if (isSolved()) { return; }

  bool foundAny = false;
  bool foundSingleBest = false;
  option bestOption;
  bestOption.nr_options = INT_MAX;
  std::vector<option> bestOptions;

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
        foundSingleBest = true;
        break;
      }

      // If this option is better, set it as the new best option.
      if (o.nr_options < bestOption.nr_options) {
        bestOptions.clear();
        bestOption = o;
        bestOptions.push_back(o);
      }

      // If it's just as good, add it to the others.
      if (o.nr_options == bestOption.nr_options) {
        bestOptions.push_back(o);
      }
    }
  }

  // If a single best option was found, implement it and go on.
  if (foundSingleBest) {
    int choice = 0;
    for (int i = 1; i <= SIZE; ++i) {
      if (bestOption.options[i]) { choice = i; break; }
    }
    setTile(bestOption.row, bestOption.col, choice);
  } else if (foundAny) {
    // If we have multiple best options, make all possible boards and pick the
    // first one that gets solved.
    for(std::vector<option>::reverse_iterator it = bestOptions.rbegin(); it != bestOptions.rend(); ++it) {
      for (int i = 1; i <= SIZE; ++i) {
        if (!it->options[i]) { continue; }
        Board b;
        this->copyTo(&b);
        b.setTile(it->row, it->col, i);
        b.solve();
        if (b.isSolved()) {
          b.copyTo(this);
          break;
        } else {
        }
      }
      // Still found nothing, this is not solveable.
      return;
    }
  } else {
    // If there were no options found there and the sudoku wasn't solved already,
    // there is no way to solve it.
    return;
  }
  solve();
}

void Board::copyTo(Board *other) {
  for (int r = 0; r < SIZE; ++r) {
    for (int c = 0; c < SIZE; ++c) {
      other->setTile(r,c,getTile(r,c));
    }
  }
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

  option o;
  o.row = r;
  o.col = c;
  o.nr_options = nr_poss;
  for (int i = 0; i <= SIZE; ++i) {
    o.options[i] = possibilities[i];
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
