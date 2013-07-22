class Solution {
 public:
  bool isLeft(char ch) { return ch == '(' || ch == '[' || ch == '{'; }
  bool isRight(char ch) { return ch == ')' || ch == ']' || ch == '}'; }
  bool isPair(char left, char right) {
    return left == '(' && right == ')' || left == '[' && right == ']' ||
           left == '{' && right == '}';
  }
  bool isValid(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      if (isLeft(s[i])) {
        st.push(s[i]);
      } else if (isRight(s[i])) {
        if (st.empty() || !isPair(st.top(), s[i]))
          return false;
        st.pop();
      }
    }
    return st.empty();
  }
};
