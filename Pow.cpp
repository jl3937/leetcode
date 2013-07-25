class Solution {
 public:
  double pow(double x, int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (n == 0)
      return 1;
    if (n > 0) {
      double r = pow(x, n / 2);
      r *= r;
      if (n % 2)
        r *= x;
      return r;
    }
    double r = pow(x, -((-n) / 2));
    r *= r;
    if (n % 2)
      r /= x;
    return r;
  }
};
