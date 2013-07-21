class Solution {
public:
  void setZeroes(vector<vector<int> > &matrix) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int non_zero_row = -1;
    for (int i = 0; i < matrix.size(); i++) {
      bool non_zero = true;
      for (int j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] == 0) {
          non_zero = false;
          break;
        }
      }
      if (non_zero) {
        non_zero_row = i;
        break;
      }
    }
    if (non_zero_row == -1) {
      for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
          matrix[i][j] = 0;
        }
      }
      return;
    }
    for (int i = 0; i < matrix.size(); i++) {
      if (i == non_zero_row)
        continue;
      bool set_zero = false;
      for (int j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] == 0) {
          matrix[non_zero_row][j] = 0;
          set_zero = true;
        }
      }
      if (set_zero) {
        for (int j = 0; j < matrix[i].size(); j++) {
          matrix[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < matrix[non_zero_row].size(); i++) {
      if (matrix[non_zero_row][i] == 0) {
        for (int j = 0; j < matrix.size(); j++) {
          matrix[j][i] = 0;
        }
      }
    }
  }
};