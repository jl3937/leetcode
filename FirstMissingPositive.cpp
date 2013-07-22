class Solution {
 public:
  int firstMissingPositive(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    for (int i = 0; i < n; i++) {
      int pos = A[i] - 1;
      while (pos >= 0 && pos < n && A[pos] != A[i]) {
        swap(A[i], A[pos]);
        pos = A[i] - 1;
      }
    }
    int i;
    for (i = 0; i < n; i++) {
      if (A[i] - 1 != i)
        return i + 1;
    }
    return i + 1;
  }
};
