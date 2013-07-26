class Solution {
public:
  int maxSubArray(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int maxSum = A[0];
    int prev = A[0];
    for (int i = 1; i < n; i++) {
      prev = A[i] + max(prev, 0);
      if (prev > maxSum)
        maxSum = prev;
    }
    return maxSum;
  }
};
