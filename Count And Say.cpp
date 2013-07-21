class Solution {
 public:
  string countAndSay(int n) {
    string r = "1";
    if (n == 1) {
      return r;
    }
    for (int i = 1; i < n; i++) {
      string old_r = r;
      r = "";
      int count = 1;
      int j;
      for (j = 1; j < old_r.size(); j++) {
        if (old_r[j] != old_r[j - 1]) {
          r += count + '0';
          r += old_r[j - 1];
          count = 1;
        } else {
          count++;
        }
      }
      r += count + '0';
      r += old_r[j - 1];
    }
    return r;
  }
};
