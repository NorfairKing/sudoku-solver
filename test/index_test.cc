#include <gtest/gtest.h>

#define TESTING
#include "index.h"

// (0,0) (1,0) (2,0) (3,0) (4,0) (5,0) (6,0) (7,0) (8,0)
// (0,1) (1,1) (2,1) (3,1) (4,1) (5,1) (6,1) (7,1) (8,1)
// (0,2) (1,2) (2,2) (3,2) (4,2) (5,2) (6,2) (7,2) (8,2)
// (0,3) (1,3) (2,3) (3,3) (4,3) (5,3) (6,3) (7,3) (8,3)
// (0,4) (1,4) (2,4) (3,4) (4,4) (5,4) (6,4) (7,4) (8,4)
// (0,5) (1,5) (2,5) (3,5) (4,5) (5,5) (6,5) (7,5) (8,5)
// (0,6) (1,6) (2,6) (3,6) (4,6) (5,6) (6,6) (7,6) (8,6)
// (0,7) (1,7) (2,7) (3,7) (4,7) (5,7) (6,7) (7,7) (8,7)
// (0,8) (1,8) (2,8) (3,8) (4,8) (5,8) (6,8) (7,8) (8,8)

TEST(index, boxIndex) {
  EXPECT_EQ(0, boxIndex(0,0));  EXPECT_EQ(0, boxIndex(1,0));  EXPECT_EQ(0, boxIndex(2,0));
  EXPECT_EQ(0, boxIndex(0,1));  EXPECT_EQ(0, boxIndex(1,1));  EXPECT_EQ(0, boxIndex(2,1));
  EXPECT_EQ(0, boxIndex(0,2));  EXPECT_EQ(0, boxIndex(1,2));  EXPECT_EQ(0, boxIndex(2,2));
  EXPECT_EQ(1, boxIndex(3,0));  EXPECT_EQ(1, boxIndex(4,0));  EXPECT_EQ(1, boxIndex(5,0));
  EXPECT_EQ(1, boxIndex(3,1));  EXPECT_EQ(1, boxIndex(4,1));  EXPECT_EQ(1, boxIndex(5,1));
  EXPECT_EQ(1, boxIndex(3,2));  EXPECT_EQ(1, boxIndex(4,2));  EXPECT_EQ(1, boxIndex(5,2));
  EXPECT_EQ(2, boxIndex(6,0));  EXPECT_EQ(2, boxIndex(7,0));  EXPECT_EQ(2, boxIndex(8,0));
  EXPECT_EQ(2, boxIndex(6,1));  EXPECT_EQ(2, boxIndex(7,1));  EXPECT_EQ(2, boxIndex(8,1));
  EXPECT_EQ(2, boxIndex(6,2));  EXPECT_EQ(2, boxIndex(7,2));  EXPECT_EQ(2, boxIndex(8,2));
  EXPECT_EQ(3, boxIndex(0,3));  EXPECT_EQ(3, boxIndex(1,3));  EXPECT_EQ(3, boxIndex(2,3));
  EXPECT_EQ(3, boxIndex(0,4));  EXPECT_EQ(3, boxIndex(1,4));  EXPECT_EQ(3, boxIndex(2,4));
  EXPECT_EQ(3, boxIndex(0,5));  EXPECT_EQ(3, boxIndex(1,5));  EXPECT_EQ(3, boxIndex(2,5));
  EXPECT_EQ(4, boxIndex(3,3));  EXPECT_EQ(4, boxIndex(4,3));  EXPECT_EQ(4, boxIndex(5,3));
  EXPECT_EQ(4, boxIndex(3,4));  EXPECT_EQ(4, boxIndex(4,4));  EXPECT_EQ(4, boxIndex(5,4));
  EXPECT_EQ(4, boxIndex(3,5));  EXPECT_EQ(4, boxIndex(4,5));  EXPECT_EQ(4, boxIndex(5,5));
  EXPECT_EQ(5, boxIndex(6,3));  EXPECT_EQ(5, boxIndex(7,3));  EXPECT_EQ(5, boxIndex(8,3));
  EXPECT_EQ(5, boxIndex(6,4));  EXPECT_EQ(5, boxIndex(7,4));  EXPECT_EQ(5, boxIndex(8,4));
  EXPECT_EQ(5, boxIndex(6,5));  EXPECT_EQ(5, boxIndex(7,5));  EXPECT_EQ(5, boxIndex(8,5));
  EXPECT_EQ(6, boxIndex(0,6));  EXPECT_EQ(6, boxIndex(1,6));  EXPECT_EQ(6, boxIndex(2,6));
  EXPECT_EQ(6, boxIndex(0,7));  EXPECT_EQ(6, boxIndex(1,7));  EXPECT_EQ(6, boxIndex(2,7));
  EXPECT_EQ(6, boxIndex(0,8));  EXPECT_EQ(6, boxIndex(1,8));  EXPECT_EQ(6, boxIndex(2,8));
  EXPECT_EQ(7, boxIndex(3,6));  EXPECT_EQ(7, boxIndex(4,6));  EXPECT_EQ(7, boxIndex(5,6));
  EXPECT_EQ(7, boxIndex(3,7));  EXPECT_EQ(7, boxIndex(4,7));  EXPECT_EQ(7, boxIndex(5,7));
  EXPECT_EQ(7, boxIndex(3,8));  EXPECT_EQ(7, boxIndex(4,8));  EXPECT_EQ(7, boxIndex(5,8));
  EXPECT_EQ(8, boxIndex(6,6));  EXPECT_EQ(8, boxIndex(7,6));  EXPECT_EQ(8, boxIndex(8,6));
  EXPECT_EQ(8, boxIndex(6,7));  EXPECT_EQ(8, boxIndex(7,7));  EXPECT_EQ(8, boxIndex(8,7));
  EXPECT_EQ(8, boxIndex(6,8));  EXPECT_EQ(8, boxIndex(7,8));  EXPECT_EQ(8, boxIndex(8,8));
}

TEST(digit, indexInBox) {
  EXPECT_EQ(0, indexInBox(0,0));  EXPECT_EQ(1, indexInBox(1,0));  EXPECT_EQ(2, indexInBox(2,0));
  EXPECT_EQ(3, indexInBox(0,1));  EXPECT_EQ(4, indexInBox(1,1));  EXPECT_EQ(5, indexInBox(2,1));
  EXPECT_EQ(6, indexInBox(0,2));  EXPECT_EQ(7, indexInBox(1,2));  EXPECT_EQ(8, indexInBox(2,2));
  EXPECT_EQ(0, indexInBox(3,0));  EXPECT_EQ(1, indexInBox(4,0));  EXPECT_EQ(2, indexInBox(5,0));
  EXPECT_EQ(3, indexInBox(3,1));  EXPECT_EQ(4, indexInBox(4,1));  EXPECT_EQ(5, indexInBox(5,1));
  EXPECT_EQ(6, indexInBox(3,2));  EXPECT_EQ(7, indexInBox(4,2));  EXPECT_EQ(8, indexInBox(5,2));
  EXPECT_EQ(0, indexInBox(6,0));  EXPECT_EQ(1, indexInBox(7,0));  EXPECT_EQ(2, indexInBox(8,0));
  EXPECT_EQ(3, indexInBox(6,1));  EXPECT_EQ(4, indexInBox(7,1));  EXPECT_EQ(5, indexInBox(8,1));
  EXPECT_EQ(6, indexInBox(6,2));  EXPECT_EQ(7, indexInBox(7,2));  EXPECT_EQ(8, indexInBox(8,2));
  EXPECT_EQ(0, indexInBox(0,3));  EXPECT_EQ(1, indexInBox(1,3));  EXPECT_EQ(2, indexInBox(2,3));
  EXPECT_EQ(3, indexInBox(0,4));  EXPECT_EQ(4, indexInBox(1,4));  EXPECT_EQ(5, indexInBox(2,4));
  EXPECT_EQ(6, indexInBox(0,5));  EXPECT_EQ(7, indexInBox(1,5));  EXPECT_EQ(8, indexInBox(2,5));
  EXPECT_EQ(0, indexInBox(3,3));  EXPECT_EQ(1, indexInBox(4,3));  EXPECT_EQ(2, indexInBox(5,3));
  EXPECT_EQ(3, indexInBox(3,4));  EXPECT_EQ(4, indexInBox(4,4));  EXPECT_EQ(5, indexInBox(5,4));
  EXPECT_EQ(6, indexInBox(3,5));  EXPECT_EQ(7, indexInBox(4,5));  EXPECT_EQ(8, indexInBox(5,5));
  EXPECT_EQ(0, indexInBox(6,3));  EXPECT_EQ(1, indexInBox(7,3));  EXPECT_EQ(2, indexInBox(8,3));
  EXPECT_EQ(3, indexInBox(6,4));  EXPECT_EQ(4, indexInBox(7,4));  EXPECT_EQ(5, indexInBox(8,4));
  EXPECT_EQ(6, indexInBox(6,5));  EXPECT_EQ(7, indexInBox(7,5));  EXPECT_EQ(8, indexInBox(8,5));
  EXPECT_EQ(0, indexInBox(0,6));  EXPECT_EQ(1, indexInBox(1,6));  EXPECT_EQ(2, indexInBox(2,6));
  EXPECT_EQ(3, indexInBox(0,7));  EXPECT_EQ(4, indexInBox(1,7));  EXPECT_EQ(5, indexInBox(2,7));
  EXPECT_EQ(6, indexInBox(0,8));  EXPECT_EQ(7, indexInBox(1,8));  EXPECT_EQ(8, indexInBox(2,8));
  EXPECT_EQ(0, indexInBox(3,6));  EXPECT_EQ(1, indexInBox(4,6));  EXPECT_EQ(2, indexInBox(5,6));
  EXPECT_EQ(3, indexInBox(3,7));  EXPECT_EQ(4, indexInBox(4,7));  EXPECT_EQ(5, indexInBox(5,7));
  EXPECT_EQ(6, indexInBox(3,8));  EXPECT_EQ(7, indexInBox(4,8));  EXPECT_EQ(8, indexInBox(5,8));
  EXPECT_EQ(0, indexInBox(6,6));  EXPECT_EQ(1, indexInBox(7,6));  EXPECT_EQ(2, indexInBox(8,6));
  EXPECT_EQ(3, indexInBox(6,7));  EXPECT_EQ(4, indexInBox(7,7));  EXPECT_EQ(5, indexInBox(8,7));
  EXPECT_EQ(6, indexInBox(6,8));  EXPECT_EQ(7, indexInBox(7,8));  EXPECT_EQ(8, indexInBox(8,8));
}
