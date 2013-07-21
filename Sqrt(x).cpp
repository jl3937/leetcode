// Newton's method.

class Solution {
 public:
  int sqrt(int x) {
    if (x == 0)
      return 0;
    double r = x / 2.0;
    double last_r;
    while (true) {
      last_r = r;
      r = (last_r + x / last_r) / 2;
      if (abs(last_r - r) < 0.00001)
        return (int)r;
    }
  }
};
