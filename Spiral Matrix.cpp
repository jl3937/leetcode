class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> r;
    int m = matrix.size();
    if (m == 0)
      return r;
    int n = matrix[0].size();
    if (n == 0)
      return r;
    int x = 0, y = 0;
    while(true) {
      for(int i = 0; i < n - 1; i++) {
        r.push_back(matrix[y][x]);
        x++;
      }
      if (m == 1) {
        r.push_back(matrix[y][x]);
        break;
      }
      for(int i = 0; i < m - 1; i++) {
        r.push_back(matrix[y][x]);
        y++;
      }
      if (n == 1) {
        r.push_back(matrix[y][x]);
        break;
      }
      for(int i = 0; i < n - 1; i++) {
        r.push_back(matrix[y][x]);
        x--;
      }
      if (m == 2) {
        r.push_back(matrix[y][x]);
        break;
      }
      for(int i = 0; i < m - 1; i++) {
        r.push_back(matrix[y][x]);
        y--;
      }
      if (n == 2)
        break;
      y++; x++;
      m -= 2;
      n -= 2;
    }
    return r;
  }
};