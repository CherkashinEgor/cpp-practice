#include "main.h"

#include <iostream>

using namespace std;

int Solution::trap(vector<int>& height) {
  int n = height.size();

  if (n == 1) {
    return 0;
  }

  // On the first pass, (going left-to-right)
  // Find a wall and keep going with the right pointer (rp) until hitting a larger or equal sized
  // wall. This means we hit the end of where water can be trapped In the process, subtract all the
  // smaller walls

  // Repeat this going the other way too

  // Small change for pull request

  int lp = n;
  int rp = 0;
  int total = 0;

  for (int i = 0; i < n; i++) {
    if (rp > i) {
      i = rp;
    }
    int lw = height[i];
    rp = i + 1;
    int sub = 0;
    while (rp < n && height[rp] < lw) {
      sub += height[rp];
      rp += 1;
    }
    if (rp >= n) {
      break;
    }
    int wall = min(lw, height[rp]);
    int distance = rp - i - 1;
    total += (wall * distance) - sub;
  }

  for (int i = n - 1; i >= 0; i--) {
    if (lp < i) {
      i = lp;
    }
    int rw = height[i];
    lp = i - 1;
    int sub = 0;
    while (lp >= 0 && height[lp] <= rw) {
      sub += height[lp];
      lp -= 1;
    }

    if (lp < 0) {
      break;
    }

    int wall = min(rw, height[lp]);
    int distance = i - lp - 1;
    total += (wall * distance) - sub;
  }

  return total;
}

// int main() {
//     Solution solution;

//     // Test cases
//     std::vector<std::vector<int>> test_cases = {
//         {0,1,0,2,1,0,1,3,2,1,2,1},
//         {4,2,0,3,2,5},
//         {4,2,3}
//     };

//     for (const auto& height : test_cases) {
//         auto height_copy = height;
//         int result = solution.trap(height_copy);
//         cout << "Input: ";
//         for (int h : height) {
//             std::cout << h << " ";
//         }
//         std::cout << "\nTrapped water: " << result << "\n\n";
//     }

//     return 0;
// }