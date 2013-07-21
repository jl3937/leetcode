class Solution {
public:
  bool isScramble(string s1, string s2) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (s1.length() != s2.length())
      return false;
    int n = s1.length();
    if (n == 1)
      return s1 == s2;
    bool s[64][64][64];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        s[1][i][j] = s1[i] == s2[j];
      }
    }
    
    for (int d = 2; d <= n; d++) {
      for (int i = 0; i + d <= n; i++) {
        for (int j = 0; j + d <= n; j++) {
          bool r = false;
          for (int f = 1; f < d; f++) {
            if(s[f][i][j] && s[d - f][i + f][j + f] ||
               s[d - f][i][j + f] && s[f][i + d - f][j]) {
              r = true;
              break;
            }
          }
          s[d][i][j] = r;
        }
      }
    }
    return s[n][0][0];
  }
};