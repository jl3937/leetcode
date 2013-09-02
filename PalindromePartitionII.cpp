// 2-step dynamic programming
// s[i...j] is palindrome if s[i+1...j-1] is palindrome and s[i] == s[j]
bool p[2048][2048];
int cut[2048];
class Solution {
public:
  int minCut(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int len = s.size();
    for (int i = len - 1; i >= 0; i--) {
      for (int j = i; j < len; j++) {
        p[i][j] = s[i] == s[j] && (i + 1 >= j - 1 || p[i + 1][j - 1]);
      }
    }
    cut[0] = -1;
    for (int i = 0; i < len; i++) {
      int min_cut = i;
      for (int j = 0; j <= i; j++) {
        if (p[j][i]) {
          min_cut = min(min_cut, cut[j] + 1);
          if (min_cut <= 1)
            break;
        }
      }
      cut[i + 1] = min_cut;
    }
    return cut[len];
  }
};
