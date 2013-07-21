class Solution {
 public:
  // Encode starts from 1, should check whether '0' is valid!
  int numDecodings(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (s.empty())
      return 0;
    if (s[0] == '0')
      return 0;
    if (s.size() == 1) {
      return true;
    }
    int prev2 = 1, prev1 = 1, cur;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == '0') {
        if (s[i - 1] != '1' && s[i - 1] != '2')
          return 0;
        cur = prev2;
      } else {
        cur = prev1;
        if ((s[i - 1] == '2' && s[i] <= '6') || s[i - 1] == '1') {
          cur += prev2;
        }
      }
      prev2 = prev1;
      prev1 = cur;
    }
    return cur;
  }
};
