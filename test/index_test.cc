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


TEST(index, index) {
  EXPECT_EQ(0 , index(0,0));
  EXPECT_EQ(1 , index(1,0));
  EXPECT_EQ(2 , index(2,0));
  EXPECT_EQ(3 , index(3,0));
  EXPECT_EQ(4 , index(4,0));
  EXPECT_EQ(5 , index(5,0));
  EXPECT_EQ(6 , index(6,0));
  EXPECT_EQ(7 , index(7,0));
  EXPECT_EQ(8 , index(8,0));
  EXPECT_EQ(9 , index(0,1));
  EXPECT_EQ(10, index(1,1));
  EXPECT_EQ(11, index(2,1));
  EXPECT_EQ(12, index(3,1));
  EXPECT_EQ(13, index(4,1));
  EXPECT_EQ(14, index(5,1));
  EXPECT_EQ(15, index(6,1));
  EXPECT_EQ(16, index(7,1));
  EXPECT_EQ(17, index(8,1));
  EXPECT_EQ(18, index(0,2));
  EXPECT_EQ(19, index(1,2));
  EXPECT_EQ(20, index(2,2));
  EXPECT_EQ(21, index(3,2));
  EXPECT_EQ(22, index(4,2));
  EXPECT_EQ(23, index(5,2));
  EXPECT_EQ(24, index(6,2));
  EXPECT_EQ(25, index(7,2));
  EXPECT_EQ(26, index(8,2));
  EXPECT_EQ(27, index(0,3));
  EXPECT_EQ(28, index(1,3));
  EXPECT_EQ(29, index(2,3));
  EXPECT_EQ(30, index(3,3));
  EXPECT_EQ(31, index(4,3));
  EXPECT_EQ(32, index(5,3));
  EXPECT_EQ(33, index(6,3));
  EXPECT_EQ(34, index(7,3));
  EXPECT_EQ(35, index(8,3));
  EXPECT_EQ(36, index(0,4));
  EXPECT_EQ(37, index(1,4));
  EXPECT_EQ(38, index(2,4));
  EXPECT_EQ(39, index(3,4));
  EXPECT_EQ(40, index(4,4));
  EXPECT_EQ(41, index(5,4));
  EXPECT_EQ(42, index(6,4));
  EXPECT_EQ(43, index(7,4));
  EXPECT_EQ(44, index(8,4));
  EXPECT_EQ(45, index(0,5));
  EXPECT_EQ(46, index(1,5));
  EXPECT_EQ(47, index(2,5));
  EXPECT_EQ(48, index(3,5));
  EXPECT_EQ(49, index(4,5));
  EXPECT_EQ(50, index(5,5));
  EXPECT_EQ(51, index(6,5));
  EXPECT_EQ(52, index(7,5));
  EXPECT_EQ(53, index(8,5));
  EXPECT_EQ(54, index(0,6));
  EXPECT_EQ(55, index(1,6));
  EXPECT_EQ(56, index(2,6));
  EXPECT_EQ(57, index(3,6));
  EXPECT_EQ(58, index(4,6));
  EXPECT_EQ(59, index(5,6));
  EXPECT_EQ(60, index(6,6));
  EXPECT_EQ(61, index(7,6));
  EXPECT_EQ(62, index(8,6));
  EXPECT_EQ(63, index(0,7));
  EXPECT_EQ(64, index(1,7));
  EXPECT_EQ(65, index(2,7));
  EXPECT_EQ(66, index(3,7));
  EXPECT_EQ(67, index(4,7));
  EXPECT_EQ(68, index(5,7));
  EXPECT_EQ(69, index(6,7));
  EXPECT_EQ(70, index(7,7));
  EXPECT_EQ(71, index(8,7));
  EXPECT_EQ(72, index(0,8));
  EXPECT_EQ(73, index(1,8));
  EXPECT_EQ(74, index(2,8));
  EXPECT_EQ(75, index(3,8));
  EXPECT_EQ(76, index(4,8));
  EXPECT_EQ(77, index(5,8));
  EXPECT_EQ(78, index(6,8));
  EXPECT_EQ(79, index(7,8));
  EXPECT_EQ(80, index(8,8));
}

TEST(indexByBox, indexByBox) {
  EXPECT_EQ(0 , indexByBox(0,0));
  EXPECT_EQ(1 , indexByBox(0,1));
  EXPECT_EQ(2 , indexByBox(0,2));
  EXPECT_EQ(3 , indexByBox(1,0));
  EXPECT_EQ(4 , indexByBox(1,1));
  EXPECT_EQ(5 , indexByBox(1,2));
  EXPECT_EQ(6 , indexByBox(2,0));
  EXPECT_EQ(7 , indexByBox(2,1));
  EXPECT_EQ(8 , indexByBox(2,2));
  EXPECT_EQ(9 , indexByBox(0,3));
  EXPECT_EQ(10, indexByBox(0,4));
  EXPECT_EQ(11, indexByBox(0,5));
  EXPECT_EQ(12, indexByBox(1,3));
  EXPECT_EQ(13, indexByBox(1,4));
  EXPECT_EQ(14, indexByBox(1,5));
  EXPECT_EQ(15, indexByBox(2,3));
  EXPECT_EQ(16, indexByBox(2,4));
  EXPECT_EQ(17, indexByBox(2,5));
  EXPECT_EQ(18, indexByBox(0,6));
  EXPECT_EQ(19, indexByBox(0,7));
  EXPECT_EQ(20, indexByBox(0,8));
  EXPECT_EQ(21, indexByBox(1,6));
  EXPECT_EQ(22, indexByBox(1,7));
  EXPECT_EQ(23, indexByBox(1,8));
  EXPECT_EQ(24, indexByBox(2,6));
  EXPECT_EQ(25, indexByBox(2,7));
  EXPECT_EQ(26, indexByBox(2,8));
  EXPECT_EQ(27, indexByBox(3,0));
  EXPECT_EQ(28, indexByBox(3,1));
  EXPECT_EQ(29, indexByBox(3,2));
  EXPECT_EQ(30, indexByBox(4,0));
  EXPECT_EQ(31, indexByBox(4,1));
  EXPECT_EQ(32, indexByBox(4,2));
  EXPECT_EQ(33, indexByBox(5,0));
  EXPECT_EQ(34, indexByBox(5,1));
  EXPECT_EQ(35, indexByBox(5,2));
  EXPECT_EQ(36, indexByBox(3,3));
  EXPECT_EQ(37, indexByBox(3,4));
  EXPECT_EQ(38, indexByBox(3,5));
  EXPECT_EQ(39, indexByBox(4,3));
  EXPECT_EQ(40, indexByBox(4,4));
  EXPECT_EQ(41, indexByBox(4,5));
  EXPECT_EQ(42, indexByBox(5,3));
  EXPECT_EQ(43, indexByBox(5,4));
  EXPECT_EQ(44, indexByBox(5,5));
  EXPECT_EQ(45, indexByBox(3,6));
  EXPECT_EQ(46, indexByBox(3,7));
  EXPECT_EQ(47, indexByBox(3,8));
  EXPECT_EQ(48, indexByBox(4,6));
  EXPECT_EQ(49, indexByBox(4,7));
  EXPECT_EQ(50, indexByBox(4,8));
  EXPECT_EQ(51, indexByBox(5,6));
  EXPECT_EQ(52, indexByBox(5,7));
  EXPECT_EQ(53, indexByBox(5,8));
  EXPECT_EQ(54, indexByBox(6,0));
  EXPECT_EQ(55, indexByBox(6,1));
  EXPECT_EQ(56, indexByBox(6,2));
  EXPECT_EQ(57, indexByBox(7,0));
  EXPECT_EQ(58, indexByBox(7,1));
  EXPECT_EQ(59, indexByBox(7,2));
  EXPECT_EQ(60, indexByBox(8,0));
  EXPECT_EQ(61, indexByBox(8,1));
  EXPECT_EQ(62, indexByBox(8,2));
  EXPECT_EQ(63, indexByBox(6,3));
  EXPECT_EQ(64, indexByBox(6,4));
  EXPECT_EQ(65, indexByBox(6,5));
  EXPECT_EQ(66, indexByBox(7,3));
  EXPECT_EQ(67, indexByBox(7,4));
  EXPECT_EQ(68, indexByBox(7,5));
  EXPECT_EQ(69, indexByBox(8,3));
  EXPECT_EQ(70, indexByBox(8,4));
  EXPECT_EQ(71, indexByBox(8,5));
  EXPECT_EQ(72, indexByBox(6,6));
  EXPECT_EQ(73, indexByBox(6,7));
  EXPECT_EQ(74, indexByBox(6,8));
  EXPECT_EQ(75, indexByBox(7,6));
  EXPECT_EQ(76, indexByBox(7,7));
  EXPECT_EQ(77, indexByBox(7,8));
  EXPECT_EQ(78, indexByBox(8,6));
  EXPECT_EQ(79, indexByBox(8,7));
  EXPECT_EQ(80, indexByBox(8,8));
}
