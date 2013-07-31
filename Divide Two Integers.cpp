class Solution {
 public:
  int divide(int dividend, int divisor) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    long long a = dividend, b = divisor;
    if (a < 0)
      a = -a;
    if (b < 0)
      b = -b;
    int i = 31;
    long long cur = 0;
    long long r = 0;
    while (i >= 0) {
      cur <<= 1;
      r <<= 1;
      cur |= (a >> i) & 1;
      if (cur >= b) {
        cur -= b;
        r |= 1;
      }
      i--;
    }
    if (dividend >> 31 ^ divisor >> 31) {
      r = -r;
    }
    return r;
  }
};
