class Solution {
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int low = -1;
    int high = m - 1;
    while (true) {
      int midA = (low + high) / 2;
      int midB = (m + n) / 2 - midA - 2;
      if (midB < -1) {
        midB = -1;
        midA = (m + n) / 2 - midB - 2;
      } else if (midB >= n) {
        midB = n - 1;
        midA = (m + n) / 2 - midB - 2;
      }
      if (midA + 1 < m && midB >=0 && A[midA + 1] < B[midB]) {
        low = midA + 1;
      } else if (midB + 1 < n && midA >= 0 && B[midB + 1] < A[midA]) {
        high = midA - 1;
      } else {
        if ((m + n) % 2 == 0) {
          int small;
          if (midA < 0)
            small = B[midB];
          else if (midB < 0)
            small = A[midA];
          else
            small = max(A[midA], B[midB]);
          int large;
          if (midA + 1 >= m)
            large = B[midB + 1];
          else if (midB + 1 >= n)
            large = A[midA + 1];
          else
            large = min(A[midA + 1], B[midB + 1]);
          return (small + large) / 2.0;
        } else {
          if (midA + 1 >= m)
            return B[midB + 1];
          if (midB + 1 >= n)
            return A[midA + 1];
          return min(A[midA + 1], B[midB + 1]);
        }
      }
    }
  }
};
