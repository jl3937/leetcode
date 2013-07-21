class Solution {
public:
  int search(int A[], int n, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int low = 0;
    int high = n - 2;
    if (A[0] > A[n - 1]) {
      int mid;
      while (low <= high) {
        mid = (low + high) / 2;
        if (A[mid] > A[n - 1] && A[mid + 1] > A[n - 1]) {
          low = mid + 1;
        } else if (A[mid] < A[0] && A[mid + 1] < A[0]) {
          high = mid - 1;
        } else {
          break;
        }
      }
      if (target >= A[0]) {
        low = 0;
        high = mid;
      } else if (target <= A[n - 1]) {
        low = mid + 1;
        high = n - 1;
      } else {
        return -1;
      }
    } else {
      low = 0;
      high = n - 1;
    }
    
    while (low <= high) {
      int mid = (low + high) / 2;
      if (target < A[mid]) {
        high = mid - 1;
      } else if (target > A[mid]) {
        low = mid + 1;
      } else {
        return mid;
      }
    }
    return -1;
  }
};