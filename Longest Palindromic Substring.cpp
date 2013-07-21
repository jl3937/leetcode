class Solution {
public:
  string longestPalindrome(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int max = 0;
    string maxString;
    for (int i = 0; i < s.length(); i++) {
      for (int j = s.length() - 1; j >= i; j--) {
        int b = i;
        int e = j;
        bool p = true;
        while (b <= e) {
          if (s[b] != s[e]) {
            p = false;
            break;
          }
          b++;
          e--;
        }
        if (p) {
          if (max < j - i + 1) {
            max = j - i + 1;
            maxString = s.substr(i, max);
          }
          break;
        }
      }
    }
    return maxString;
  }
};
