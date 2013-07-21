// recursion -> dynamic programming -> greedy!

class Solution {
 public:
  bool isMatch(const char* s, const char* p) {
    int start_s = 0, start_p = 0;
    int cur_s = 0, cur_p = 0;
    bool allow_advance = false;
    while (s[cur_s] != '\0') {
      if (s[cur_s] == p[cur_p] || p[cur_p] == '?') {
        cur_s++;
        cur_p++;
      } else if (p[cur_p] == '*') {
        allow_advance = true;
        while (p[cur_p] == '*') {
          cur_p++;
          start_s = cur_s;
          start_p = cur_p;
        }
      } else {
        if (!allow_advance)
          return false;
        start_s++;
        cur_s = start_s;
        cur_p = start_p;
      }
    }
    if (p[cur_p] == '*') {
      while (p[cur_p] == '*') {
        cur_p++;
        start_s = cur_s;
        start_p = cur_p;
      }
    }
    return p[cur_p] == 0;
  }
};
