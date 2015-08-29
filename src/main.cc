#include <iostream>
#include "board.h"

int main() {
  Board b;
  std::cin >> b;
  std::cout << b;
  b.solve();
  std::cout << b;
}
