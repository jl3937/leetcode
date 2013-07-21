class Solution {
  vector<string> r;
public:
  // for len = 2 or 3, value can't start with 0
  bool valid(int value, int len) {
    if (len == 1) {
      return true;
    }
    if (len == 2) {
      return value >= 10 && value <= 99;
    }
    if (len == 3) {
      return value >= 100 && value <= 255;
    }
  }
  void restoreIPAddress(string s, int pos, int num) {
    if (num == 0) {
      if (pos == s.length())
        r.push_back(s.substr(0, s.length() - 1));
      return;
    }
    for (int l = 1; l <= 3; l++) {
      if (s.length() - pos < l + num - 1)
        break;
      int v = atoi(s.substr(pos, l).c_str());
      if (valid(v, l)) {
        restoreIPAddress(s.substr(0, pos + l) + "." +
                         s.substr(pos + l, s.length() - pos - l),
                         pos + l + 1, num - 1);
      }
    }
  }
  vector<string> restoreIpAddresses(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    r.clear();
    restoreIPAddress(s, 0, 4);
    return r;
  }
};