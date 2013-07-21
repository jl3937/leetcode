class Solution {
 public:
  int removeDuplicates(int A[], int n) {
    if (n < 3) {
      return n;
    }
    int cur = 2;
    for (int i = 2; i < n; i++) {
      if (A[i] != A[i - 1]) {
        if (i + 1 < n && A[i + 1] == A[i]) {
          A[cur++] = A[i++];
        }
        A[cur++] = A[i];
      } else if (A[i] != A[i - 2]) {
        A[cur++] = A[i];
      }
    }
    return cur;
  }
};
