class Solution {
public:
  vector<int> searchRange(int A[], int n, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> r;
    int low = 0;
    int high = n - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if ((mid == 0 || A[mid - 1] != target) && A[mid] == target) {
        r.push_back(mid);
        break;
      } else if (A[mid] >= target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    if (r.empty()) {
      r.push_back(-1);
      r.push_back(-1);
      return r;
    }
    low = 0;
    high = n - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if ((mid == n - 1 || A[mid + 1] != target) && A[mid] == target) {
        r.push_back(mid);
        return r;
      } else if (A[mid] <= target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    } 
  }
};
