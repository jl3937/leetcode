class Solution {
public:
  int singleNumber(int A[], int n) {
    // Note: The Solution object is instantiated only once and is reused by each
    // test case.
    int single = A[0];
    for (int i = 1; i < n; i++) {
      single ^= A[i];
    }
    return single;
  }
};
