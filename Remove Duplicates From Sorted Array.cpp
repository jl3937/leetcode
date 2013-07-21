class Solution {
 public:
  int removeDuplicates(int A[], int n) {
    if (n == 0) {
      return 0;
    }
    int cur = 0;
    A[cur++] = A[0];
    for(int i = 1; i < n; i++) {
      if (A[i] != A[i - 1]) {
        A[cur++] = A[i];
      }
    }
    return cur;
  }
};
