#include <iostream>
#include "main.h"
#include "board.h"

int main() {
  Board* b = new Board;
  b->setTile(1, 1, 1);
  std::cout << b->getTile(0,0);
  std::cout << b->getTile(1,1);
  return 0;
}
