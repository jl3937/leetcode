class Solution {
 public:
  int climbStairs(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (n < 2)
      return 1;
    int prev2 = 1, prev1 = 1;
    int cur;
    for (int i = 2; i <= n; i++) {
      cur = prev2 + prev1;
      prev2 = prev1;
      prev1 = cur;
    }
    return cur;
  }
};
