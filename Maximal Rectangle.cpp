class Solution {
public:
  int maximalRectangle(vector<vector<char> > &matrix) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (matrix.size() == 0)
      return 0;
    
    vector<vector<int> > area;
    int m = matrix.size();
    int n = matrix[0].size();
    
    for (int i = 0; i < n; i++) {
      vector<int> area_row;
      for (int j = 0; j < n; j++) {
        area_row.push_back(-1);
      }
      area.push_back(area_row);
    }
    
    int max = 0;
    
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = j; k < n; k++) {
          bool full = true;
          for (int l = j; l <= k; l++) {
            if (matrix[i][l] != '1') {
              full = false;
              break;
            }
          }
          if (full) {
            if (area[j][k] == -1) {
              area[j][k] = i;
            }
            if ((k - j + 1) * (i - area[j][k] + 1) > max)
              max = (k - j + 1) * (i - area[j][k] + 1);
          } else {
            area[j][k] = -1;
          }
        }
      }
    }
    return max;
  }
};