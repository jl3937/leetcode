class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    bool interleave[512][512];
    int m = s1.size(), n = s2.size();
    if (m + n != s3.length())
      return false;
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= n; j++) {
        if (i == 0 && j == 0) {
          interleave[i][j] = true;
        } else {
          interleave[i][j] =
              j > 0 && interleave[i][j - 1] && s2[j - 1] == s3[i + j - 1] ||
              i > 0 && interleave[i - 1][j] && s1[i - 1] == s3[i + j - 1];
        }
      }
    }
    return interleave[m][n];
  }
};
