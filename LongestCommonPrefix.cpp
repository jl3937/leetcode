class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    string r;
    if (strs.empty())
      return r;
    int j = 0;
    while (true) {
      if (j == strs[0].size())
        return r;
      char ch = strs[0][j];
      for (int i = 0; i < strs.size(); i++) {
        if (strs[i].size() == j)
          return r;
        if (strs[i][j] != ch) {
          return r;
        }
      }
      r += ch;
      j++;
    }
    return r;
  }
};
