class Solution {
 public:
  int jump(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (n == 1)
      return 0;
    int last_max = -1;
    int max = 0;
    int step = 0;
    while (true) {
      step++;
      int i = last_max + 1;
      last_max = max;
      for (; i <= last_max; i++) {
        if (i + A[i] > max) {
          max = i + A[i];
          if (max >= n - 1)
            return step;
        }
      }
    }
    return -1;
  }
};
