#include "constants.h"
#include "index.h"

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



