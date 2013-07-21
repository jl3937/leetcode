class Solution {
public:
  string convert(string s, int nRows) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (nRows == 1)
      return s;
    string r = "";
    int n = 2 * (nRows - 1);
    for (int i = 0; i < s.length(); i += n)
      r = r + s[i];
    for (int i = 1; i < nRows - 1; i++) {
      for (int j = 0; j < s.length(); j += n) {
        if (j + i < s.length()) {
          r = r + s[j + i];
          if (j + n - i < s.length()) {
            r = r + s[j + n - i];
          }
        }
      }
    }
    for (int i = 0; i < s.length(); i += n) {
      if (i + nRows - 1 < s.length())
        r = r + s[i + nRows - 1];
    }
    return r;
  }
};
