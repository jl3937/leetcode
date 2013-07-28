class Solution {
public:
  bool isPalindrome(int x) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (x < 0)
      return false;
    int high = 1;
    while (x / high >= 10) {
      high *= 10;
    }
    while (high >= 10) {
      int d = x / high;
      x %= high;
      if (x % 10 != d)
        return false;
      x /= 10;
      high /= 100;
    }
    return true;
  }
};
