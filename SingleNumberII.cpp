class Solution {
public:
  int singleNumber(int A[], int n) {
    // Note: The Solution object is instantiated only once and is reused by each
    // test case.
    int sum[32];
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 32; j++) {
        sum[j] += (A[i] >> j) & 1;
      }
    }
    int r = 0;
    for (int i = 0; i < 32; i++) {
      r += (sum[i] % 3) << i;
    }
    return r;
  }
};
