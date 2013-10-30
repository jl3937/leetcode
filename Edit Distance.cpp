class Solution {
public:
  int minDistance(string word1, string word2) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int s[512][512];
    int m = word1.size();
    int n = word2.size();
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= n; j++) {
        s[i][j] = i + j;
        if (i > 0 && j > 0) {
          if (word1[i - 1] == word2[j - 1]) {
            if (s[i - 1][j - 1] < s[i][j]) {
              s[i][j] = s[i - 1][j - 1];
            }
          } else {
            if (s[i - 1][j - 1] + 1 < s[i][j]) {
              s[i][j] = s[i - 1][j - 1] + 1;
            }
          }
        }
        if (i > 0) {
          if (s[i - 1][j] + 1 < s[i][j]) {
            s[i][j] = s[i - 1][j] + 1;
          }
        }
        if (j > 0) {
          if (s[i][j - 1] + 1 < s[i][j]) {
            s[i][j] = s[i][j - 1] + 1;
          }
        }
      }
    }
    return s[m][n];
  }
};
