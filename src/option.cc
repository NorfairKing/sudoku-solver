#include <iostream>
#include "option.h"

bool operator < (const option& a, const option& b) {
  return a.nr_options > b.nr_options;
}

std::ostream& operator << (std::ostream &out, option &option)
{
  out << "(" << option.row << ", " << option.col << ")";
  out << " nr_options:" << option.nr_options;
  out << " default:" << option.default_option;
  out << std::endl;
  return out;
}
