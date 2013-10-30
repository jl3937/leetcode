class Solution {
  int longest, start, len;
  void updateLongest(string &s, int left, int right, int length) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      length += 2;
      left--;
      right++;
    }
    if (length > longest) {
      longest = length;
      start = left + 1;
      len = right - left - 1;
    }
  }
  
public:
  string longestPalindrome(string s) {
    if (s.empty())
      return s;
    longest = 0;
    for (int i = 0; i < s.size(); i++) {
      updateLongest(s, i - 1, i + 1, 1);
      updateLongest(s, i, i + 1, 0);
    }
    return s.substr(start, len);
  }
};
