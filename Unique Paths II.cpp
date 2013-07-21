class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int p[128][128];
    p[0][0] = 1 - obstacleGrid[0][0];
    for (int i = 1; i < n; i++) {
      p[0][i] = p[0][i - 1] * (1 - obstacleGrid[0][i]);
    }
    for(int i = 1; i < m; i++) {
      p[i][0] = p[i - 1][0] * (1 - obstacleGrid[i][0]);
      for (int j = 0; j < n; j++) {
        if (!obstacleGrid[i][j])
          p[i][j] = p[i - 1][j] + p[i][j - 1];
        else
          p[i][j] = 0;
      }
    }
    return p[m - 1][n - 1];
  }
};