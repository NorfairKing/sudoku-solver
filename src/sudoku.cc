#include <iostream>
#include "board.h"

int main() {
  Board b;
  std::cin >> b;
  std::cout << b;
  bool solved = b.isSolved();
  //std::cout << BLOCK_SUM << std::endl;
  if (solved) {
    std::cout << "Solved" << std::endl;
  } else {
    std::cout << "Not solved" << std::endl;
  }
  return 0;
}
