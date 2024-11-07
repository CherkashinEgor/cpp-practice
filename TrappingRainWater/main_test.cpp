#include "main.h"

#include <gtest/gtest.h>

class SolutionTest : public ::testing::Test {
 protected:
  TrappingRainWaterSolution solution;
};

TEST_F(SolutionTest, TrapTests) {
  const int case1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  const int case2[] = {4, 2, 0, 3, 2, 5};
  const int case3[] = {4, 2, 3};
  const int case4[] = {3, 2, 0, 2, 3};
  const int case5[] = {5};
  const int case6[] = {1, 2, 3, 4, 5};
  const int case7[] = {3, 3, 3, 3, 3};

  EXPECT_EQ(solution.trap(std::span(case1)), 6);
  EXPECT_EQ(solution.trap(std::span(case2)), 9);
  EXPECT_EQ(solution.trap(std::span(case3)), 1);
  EXPECT_EQ(solution.trap(std::span(case4)), 5);
  EXPECT_EQ(solution.trap(std::span<const int>{}), 0);
  EXPECT_EQ(solution.trap(std::span(case5)), 0);
  EXPECT_EQ(solution.trap(std::span(case6)), 0);
  EXPECT_EQ(solution.trap(std::span(case7)), 0);
}

