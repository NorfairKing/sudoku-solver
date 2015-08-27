#include <iostream>
#include "main.h"
#include "board.h"

int main() {
  Board b;
  std::cin >> b;
  std::cout << b;
  bool solved = b.isSolved();
  if (solved) {
    std::cout << "Solved" << std::endl;
  } else {
    std::cout << "Not solved" << std::endl;
  }
}
