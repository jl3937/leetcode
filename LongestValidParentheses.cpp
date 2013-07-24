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
        i++;
      } else if (left) {
        left--;
        if (left == 0) {
          if (i - start + 1 > max)
            max = i - start + 1;
        }
        i++;
      } else {
        while (i < n && s[i] == ')') {
          i++;
        }
        start = i;
      }
    }
    return max;
  }
};

