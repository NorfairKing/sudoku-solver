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
    sum += 1 << (tile[r][i] - 1);
  }
  return sum == 511;
}

bool Board::checkColumn(int c) {
  short sum = 0;
  for (int i = 0; i < SIZE; ++i) {
    sum += 1 << (tile[i][c] - 1);
  }
  return sum == 511;
}

bool Board::checkBox(int b) {
  short sum = 0;
  const int blockSize = SIZE / 3;
  const int blockRow = b / blockSize;
  const int blockCol = b % blockSize;
  int rowInBlock;
  int colInBlock;
  int row;
  int col;
  for (int i = 0; i < SIZE; ++i) {
    rowInBlock = i / blockSize;
    colInBlock = i % blockSize;
    row = blockRow*blockSize + rowInBlock;
    col = blockCol*blockSize + colInBlock;
    sum += 1 << (tile[row][col] - 1);
  }
  return sum == 511;
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
