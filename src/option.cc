#include <iostream>
#include "option.h"

bool operator < (const option& a, const option& b) {
  return a.nr_options < b.nr_options;
}
