class Solution {
  const char* five = "VLD";
  const char* one = "IXCM";
public:
  string intToRoman(int num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    string r = "";
    int base = 10000;
    for (int i = 3; i >= 0; i--) {
      base /= 10;
      int d = num / base;
      num -= d * base;
      if (d == 4 || d == 9) {
        r = r + one[i];
        if (d == 9) {
          r = r + one[i + 1];
          continue;
        }
        d += 1;
      }
      if (d >= 5) {
        r = r + five[i];
        d -= 5;
      }
      for (int j = 0; j < d; j++) {
        r = r + one[i];
      }
    }
    return r;
  }
};