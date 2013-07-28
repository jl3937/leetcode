class Solution {
public:
  bool isMatch(const char *s, const char *p) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    return isMatch(s, p, 0, 0);
  }
  bool isMatch(const char *s, const char *p, int i, int j) {
    if (p[j] == '\0') {
      return s[i] == '\0';
    } else if (p[j + 1] == '*') {
      if (isMatch(s, p, i, j + 2))
        return true;
      for (int k = 0; s[i + k] != '\0' && p[j] == '.' || s[i + k] == p[j];
           k++) {
        if (isMatch(s, p, i + k + 1, j + 2))
          return true;
      }
      return false;
    }
    return (s[i] != '\0' && p[j] == '.' || s[i] == p[j]) &&
           isMatch(s, p, i + 1, j + 1);
  }
};
