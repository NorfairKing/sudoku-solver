#ifndef option_h__
#define option_h__

struct option {
  int row;
  int col;
  int nr_options;
  int default_option;
  friend bool operator < (const option& a, const option& b);
};

#endif
