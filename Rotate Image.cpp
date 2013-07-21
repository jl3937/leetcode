class Solution {
public:
  void rotate(vector<vector<int> > &matrix) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int n = matrix.size();
    int length = n - 1;
    for (int l = 0; l < n / 2; l++) {
      for (int i = 0; i < length; i++) {
        int tmp = matrix[l][l + i];
        matrix[l][l + i] = matrix[n - 1 - l - i][l];
        matrix[n - 1 - l - i][l] = matrix[n - 1 - l][n - 1 - l - i];
        matrix[n - 1 - l][n - 1 - l - i] = matrix[l + i][n - 1 - l];
        matrix[l + i][n - 1 - l] = tmp;
      }
      length -= 2;
    }
  }
};