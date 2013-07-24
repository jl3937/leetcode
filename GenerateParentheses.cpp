class Solution {
  vector<string> r;

 public:
  vector<string> generateParenthesis(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    r.clear();
    string s;
    generateParenthesis(n, 0, 0, s);
    return r;
  }
  void generateParenthesis(int n, int left, int right, string& s) {
    if (left == n && right == n) {
      r.push_back(s);
      return;
    }
    if (right < left) {
      s.push_back(')');
      generateParenthesis(n, left, right + 1, s);
      s.pop_back();
    }
    if (left < n) {
      s.push_back('(');
      generateParenthesis(n, left + 1, right, s);
      s.pop_back();
    }
  }
};
