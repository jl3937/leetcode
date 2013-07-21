class Solution {
  const char* five = "VLDN";
  const char* one = "IXCMN";
public:
  int romanToInt(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int r = 0;
    int i = 0;
    while (i < s.length()) {
      bool ctn = false;
      for (int j = 0; j < 3; j++) {
        if (five[j] == s[i]) {
          r += 5 * pow(10.0, j);
          ctn = true;
          break;
        }
      }
      if (ctn) {
        i++;
        continue;
      }
      for (int j = 0; j < 4; j++) {
        if (one[j] == s[i]) {
          r += pow(10.0, j);
          if (i + 1 < s.length()) {
            if (s[i + 1] == five[j] || s[i + 1] == one[j + 1]) {
              r -= 2 * pow(10.0, j);
            }
          }
          break;
        }
      }
      i++;
    }
    return r;
  }
};