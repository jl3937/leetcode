class Solution {
public:
  int searchInsert(int A[], int n, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int low = 0, high = n - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (A[mid] == target) {
        return mid;
      } else if (A[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }
};
