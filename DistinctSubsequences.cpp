class Solution {
public:
  int numDistinct(string S, string T) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int num[11000];
    int old_num[11000];
    int m = S.size(), n = T.size();
    for (int i = 0; i <= n; i++) {
      memcpy(old_num, num, sizeof(old_num));
      for (int j = 0; j <= m; j++) {
        if (i == 0) {
          num[j] = 1;
          continue;
        }
        if (i > j) {
          num[j] = 0;
          continue;
        }
        num[j] = num[j - 1];
        if (S[j - 1] == T[i - 1]) {
          num[j] += old_num[j - 1];
        }
      }
    }
    return num[m];
  }
};
