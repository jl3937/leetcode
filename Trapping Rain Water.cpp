class Solution {
public:
  int trap(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (n == 1)
      return 0;
    int h = A[0];
    int l = 0;
    int w = 0;
    int sum = 0;
    for (int i = 1; i < n; i++) {
      if (A[i] < h) {
        w += h - A[i];
      } else {
        h = A[i];
        l = i;
        sum += w;
        w = 0;
      }
    }
    if (w != 0) {
      h = A[n - 1];
      w = 0;
      for (int i = n - 2; i >= l; i--) {
        if (A[i] < h) {
          w += h - A[i];
        } else {
          h = A[i];
          sum += w;
          w = 0;
        }
      }
    }
    return sum;
  }
};