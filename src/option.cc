#include <iostream>
#include <bitset>
#include "option.h"

bool operator < (const option& a, const option& b) {
  return a.nr_options > b.nr_options;
}

std::ostream& operator << (std::ostream &out, option &option)
{
  out << "(" << option.row << ", " << option.col << ")";
  out << " nr_options: " << option.nr_options;
  out << " options: ";
  std::bitset<SIZE> x(option.options);
  std::cout << x;
  out << std::endl;
  return out;
}

bool has_option(const option& o, int i) {
  return (((o.options >> (i - 1)) & 1) == 1);
}
