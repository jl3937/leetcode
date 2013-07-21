class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int max = 0;
    bool c[26];
    for (int i = 0; i < s.length(); i++) {
      int j;
      memset(c, 0, sizeof(c));
      for (j = i; i < s.length(); j++) {
        if (c[s[j] - 'a']) {
          break;
        } else {
          c[s[j] - 'a'] = true;
        }
      }
      if (j - i > max)
        max = j - i;
    }
    return max;
  }
};
