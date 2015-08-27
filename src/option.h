#ifndef option_h__
#define option_h__

#include <iostream>

struct option {
  int row;
  int col;
  int nr_options;
  int default_option;
  friend bool operator < (const option& a, const option& b);
  friend std::ostream& operator << (std::ostream& out, option& option);
};

#endif
