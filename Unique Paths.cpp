class Solution {
public:
  int uniquePaths(int m, int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int p[128][128];
    for (int i = 0; i < n; i++) {
      p[0][i] = 1;
    }
    for(int i = 1; i < m; i++) {
      p[i][0] = 1;
      for (int j = 0; j < n; j++) {
        p[i][j] = p[i - 1][j] + p[i][j - 1];
      }
    }
    return p[m - 1][n - 1];
  }
};