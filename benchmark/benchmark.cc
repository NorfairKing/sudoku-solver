#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

#include "board.h"

#define DATA_PATH "data/50_sudokus.txt"

int main() {
  std::vector<Board> boards;
  std::ifstream myfile;

  Board b;
  myfile.open(DATA_PATH);
  for(int i = 0; i < 50; ++i) {
    myfile.ignore(256, '\n'); //Ignore number line
    //myfile.get(); // get the end of line
    myfile >> b;
    boards.push_back(b);
  }
  myfile.close();

  std::clock_t start = std::clock();
  for (int i = 0; i < 50; ++i) {
    boards[i].solve();
  }
  std::clock_t end = std::clock();
  std::cout << "Time: " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms for 50 sudokus" << std::endl;

  return 0;
}
