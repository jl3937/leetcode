class Solution {
 public:
  int longestValidParentheses(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int n = s.size();
    int i = 0;
    stack<char> par;
    while (i < n && s[i] == ')') {
      i++;
    }
    int start = i;
    while (i < n) {

    }
    if (!par.empty())
    return i - start;
  }
};

