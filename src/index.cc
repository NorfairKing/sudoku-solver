#include "constants.h"
#include "index.h"

int index(int row, int col) {
  return col * SIZE + row;
}

int indexByBox(int box, int i) {
  int blockRow = box % BLOCK_SIZE;
  int blockCol = box / BLOCK_SIZE;
  int rowInBlock = i % BLOCK_SIZE;
  int colInBlock = i / BLOCK_SIZE;
  return index(blockRow * BLOCK_SIZE + rowInBlock, blockCol * BLOCK_SIZE + colInBlock);
}

int boxIndex(int r, int c) {
  int boxRow = r / BLOCK_SIZE;
  int boxCol = c / BLOCK_SIZE;
  return boxCol * BLOCK_SIZE  + boxRow;
}

int indexInBox(int r, int c) {
  int rowIndex = r % BLOCK_SIZE;
  int colIndex = c % BLOCK_SIZE;
  return colIndex * BLOCK_SIZE + rowIndex;
}



