class Solution {
 public:
  int atoi(const char* str) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (str[0] == 0)
      return 0;
    int i = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' ||
           str[i] == '\n') {
      i++;
    }

    long long val = 0;
    bool negative = false;
    if (str[i] == '-') {
      negative = true;
      i++;
    } else if (str[i] == '+') {
      i++;
    }
    while (str[i] && isdigit(str[i])) {
      if (INT_MAX / 10 >= val) {
        val *= 10;
        int d = str[i] - '0';
        if (INT_MAX - d >= val || d != 0 && negative && INT_MAX - d + 1 >= val)
          val += d;
        else
          return negative ? INT_MIN : INT_MAX;
      } else {
        return negative ? INT_MIN : INT_MAX;
      }
      i++;
    }
    return negative ? -val : val;
  }
};
