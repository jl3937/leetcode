class Solution {
public:
  void merge(int A[], int m, int B[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int i = m + n - 1;
    int i_a = m - 1;
    int i_b = n - 1;
    while (i >= 0) {
      if (i_b < 0 || i_a >= 0 && A[i_a] > B[i_b]) {
        A[i] = A[i_a];
        i_a--;
      } else {
        A[i] = B[i_b];
        i_b--;
      }
      i--;
    }
  }
};
