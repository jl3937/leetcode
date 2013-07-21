class Solution {
public:
  int divide(int dividend, int divisor) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    long long dividend_ll = dividend;
    long long divisor_ll = divisor;
    bool negative = false;
    if (dividend_ll < 0) {
      dividend_ll = -dividend_ll;
      negative = !negative;
    }
    if (divisor_ll < 0) {
      negative = !negative;
      divisor_ll = -divisor_ll;
    }
    
    long long r;
    int i = 31;
    long long cur = 0;
    while (i >= 0) {
      int d = 0;
      cur <<= 1;
      cur |= (dividend_ll >> i) & 1;
      while (cur >= divisor_ll) {
        cur -= divisor_ll;
        d++;
      }
      r <<= 1;
      r |= d;
      i--;
    }
    if (negative)
      r = -r;
    return r;
  }
};