class Solution {
 public:
  int maximalRectangle(vector<vector<char> >& matrix) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int area[512][512];
    memset(area, 0, sizeof(area));
    int m = matrix.size();
    if (m == 0)
      return 0;
    int n = matrix[0].size();
    int max_area = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = j; k < n; k++) {
          if (matrix[i][k] == '1' && (j == k || area[j][k - 1])) {
            area[j][k] += k - j + 1;
            max_area = max(max_area, area[j][k]);
          } else {
            area[j][k] = 0;
          }
        }
      }
    }
    return max_area;
  }
};
