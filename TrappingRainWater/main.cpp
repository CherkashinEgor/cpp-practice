#include "main.h"


int TrappingRainWaterSolution::trap(std::span<const int> height) {
  // Get the size of the elevation map
  size_t n = height.size();

  // Edge case: can't trap water with single element
  if (n == 1) {
    return 0;
  }

  // lp (left pointer) and rp (right pointer) track boundaries of water sections
  int lp = n;
  int rp = 0;
  int total = 0;

  // First pass: scan left to right looking for trapped water
  for (int i = 0; i < n; i++) {
    // Skip already processed sections
    if (rp > i) {
      i = rp;
    }
    // Left wall height
    int lw = height[i];
    rp = i + 1;
    // Track height of bars between walls
    int sub = 0;
    // Find right wall: first element that's >= left wall
    while (rp < n && height[rp] < lw) {
      sub += height[rp];
      rp += 1;
    }
    // If no right wall found, can't trap water
    if (rp >= n) {
      break;
    }
    // Calculate water trapped between walls:
    // 1. Find smaller wall height (water can't be higher than min wall)
    // 2. Multiply by distance between walls
    // 3. Subtract height of bars between walls
    int wall = std::min(lw, height[rp]);
    int distance = rp - i - 1;
    total += (wall * distance) - sub;
  }

  // Second pass: scan right to left
  // This catches cases where water is trapped by a higher wall on the left
  for (int i = n - 1; i >= 0; i--) {
    // Skip already processed sections
    if (lp < i) {
      i = lp;
    }
    // Right wall height
    int rw = height[i];
    lp = i - 1;
    // Track height of bars between walls
    int sub = 0;
    // Find left wall: first element that's > right wall
    while (lp >= 0 && height[lp] <= rw) {
      sub += height[lp];
      lp -= 1;
    }
    // If no left wall found, can't trap water
    if (lp < 0) {
      break;
    }
    // Calculate water trapped between walls (same logic as above)
    int wall = std::min(rw, height[lp]);
    int distance = i - lp - 1;
    total += (wall * distance) - sub;
  }

  return total;
}