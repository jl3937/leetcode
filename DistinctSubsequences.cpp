class Solution {
public:
  int numDistinct(string S, string T) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int m = S.size(), n = T.size();
    int num[50];
    memset(num, 0, sizeof(num));
    num[0] = 1;
    for (int i = 1; i <= m; i++) {
      for (int j = min(n, i); j >= 1; j--) {
        num[j] = num[j - 1] * (S[i - 1] == T[j - 1]) + num[j];
      }
    }
    return num[n];
  }
};
