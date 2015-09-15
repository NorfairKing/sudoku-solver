#ifndef option_h__
#define option_h__

#include <iostream>
#include "constants.h"

struct option {
  int row;
  int col;
  int nr_options;
  int options;
  friend bool operator < (const option& a, const option& b);
  friend std::ostream& operator << (std::ostream& out, option& option);
};

bool has_option(const option& o, int i);

#endif
