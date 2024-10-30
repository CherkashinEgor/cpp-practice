#include "main.h"

#include <gtest/gtest.h>

class SolutionTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(SolutionTest, Example1) {
  std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  EXPECT_EQ(solution.trap(height), 6);
}

TEST_F(SolutionTest, Example2) {
  std::vector<int> height = {4, 2, 0, 3, 2, 5};
  EXPECT_EQ(solution.trap(height), 9);
}

TEST_F(SolutionTest, Example3) {
  std::vector<int> height = {4, 2, 3};
  EXPECT_EQ(solution.trap(height), 1);
}

TEST_F(SolutionTest, Example4) {
  std::vector<int> height = {3, 2, 0, 2, 3};
  EXPECT_EQ(solution.trap(height), 5);
}

TEST_F(SolutionTest, EmptyVector) {
  std::vector<int> height = {};
  EXPECT_EQ(solution.trap(height), 0);
}

TEST_F(SolutionTest, SingleElement) {
  std::vector<int> height = {5};
  EXPECT_EQ(solution.trap(height), 0);
}

TEST_F(SolutionTest, NoWaterTrapped) {
  std::vector<int> height = {1, 2, 3, 4, 5};
  EXPECT_EQ(solution.trap(height), 0);
}

TEST_F(SolutionTest, AllSameHeight) {
  std::vector<int> height = {3, 3, 3, 3, 3};
  EXPECT_EQ(solution.trap(height), 0);
}

// int main(int argc, char **argv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
