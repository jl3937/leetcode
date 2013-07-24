class Solution {
 public:
  int longestValidParentheses(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int n = s.size();
    int i = 0;
    int max = 0;
    int left = 0;
    int start = 0;
    while (i < n) {
      if (s[i] == '(') {
        left++;
      } else if (left) {
        left--;
        if (left == 0) {
          if (i - start + 1 > max)
            max = i - start + 1;
        }
      } else {
        start = i + 1;
      }
      i++;
    }
    if (!left)
      return max;

    i = n - 1;
    int end = start;
    start = i;
    int right = 0;
    while (i >= end) {
      if (s[i] == ')')
        right++;
      else if (right) {
        right--;
        if (right == 0) {
          if (start - i + 1 > max) {
            max = start - i + 1;
          }
        }
      } else {
        start = i - 1;
      }
      i--;
    }
    return max;
  }
};

