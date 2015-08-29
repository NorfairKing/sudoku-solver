#ifndef option_h__
#define option_h__

#include <iostream>
#include "constants.h"

struct option {
  int row;
  int col;
  int nr_options;
  bool options[SIZE + 1];
  friend bool operator < (const option& a, const option& b);
  friend std::ostream& operator << (std::ostream& out, option& option);
};

#endif
