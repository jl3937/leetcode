bool p[2048][2048]; // p[i][j] indicates whether s[i...j] is palindrome

class Solution {
  vector<vector<string> > r;
public:
  vector<vector<string> > partition(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int len = s.size();
    for (int i = len - 1; i >= 0; i--) {
      for (int j = i; j < len; j++) {
        p[i][j] = s[i] == s[j] && (i + 1 >= j - 1 || p[i + 1][j - 1]);
      }
    }
    r.clear();
    vector<string> row;
    partition(s, row, 0);
    return r;
  }
  void partition(string s, vector<string> &row, int start) {
    if (start == s.size()) {
      r.push_back(row);
      return;
    }
    for (int end = start; end < s.size(); end++) {
      if (p[start][end]) {
        row.push_back(s.substr(start, end - start + 1));
        partition(s, row, end + 1);
        row.pop_back();
      }
    }
  }
};
