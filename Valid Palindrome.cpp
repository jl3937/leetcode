class Solution {
 public:
  int format(char ch) {
    if (ch <= 'z' && ch >= 'a') {
      return ch - 'a';
    }
    if (ch <= 'Z' && ch >= 'A') {
      return ch - 'A';
    }
    if (ch <= '9' && ch >= '0') {
      return ch - '0' + 26;
    }
    return -1;
  }
  bool isPalindrome(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int b = 0, e = s.length() - 1;
    while (true) {
      int ch_b, ch_e;
      while (b < s.length() && (ch_b = format(s[b])) == -1) {
        b++;
      }
      while (e >= 0 && (ch_e = format(s[e])) == -1) {
        e--;
      }
      if (b >= e) return true;
      if (ch_b != ch_e) return false;
      b++;
      e--;
    }
    return true;
  }
};
