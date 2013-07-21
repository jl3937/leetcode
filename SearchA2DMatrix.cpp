class Solution {
 public:
  bool searchMatrix(vector<vector<int> >& matrix, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int rowIndex = -1;
    int low = 0;
    int high = matrix.size() - 2;
    if (target < matrix[0][0]) {
      return false;
    }
    if (high != -1) {
      while (low <= high) {
        int mid = (low + high) / 2;
        if (target >= matrix[mid][0] && target < matrix[mid + 1][0]) {
          rowIndex = mid;
          break;
        } else if (target >= matrix[mid + 1][0]) {
          low = mid + 1;
        } else if (target < matrix[mid][0]) {
          high = mid - 1;
        }
      }
      if (rowIndex == -1) {
        rowIndex = matrix.size() - 1;
      }
    } else {
      rowIndex = 0;
    }
    vector<int> row(matrix[rowIndex]);
    high = row.size() - 1;
    low = 0;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (row[mid] == target) {
        return true;
      }
      if (row[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return false;
  }
};
