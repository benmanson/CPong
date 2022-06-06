#include "gtest/gtest.h"

TEST(Pong, BasicTest) {
  EXPECT_STRNE("hello", "world");
  EXPECT_EQ(7 * 6, 42);
}

TEST(Pong, BasicTest2) {
  ASSERT_EQ(7 * 6, 42);
}

TEST(Pong, BasicTest3) {
  ASSERT_NE(7 * 6, 43);  
}