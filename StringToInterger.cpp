class Solution {
public:
  int atoi(const char *str) {
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
      val = 10 * val + str[i] - '0';
      if (!negative && val > INT_MAX)
        return INT_MAX;
      if (negative && val - 1 > INT_MAX)
        return INT_MIN;
      i++;
    }
    return negative ? -val : val;
  }
};
