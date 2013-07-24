class Solution {
  vector<vector<string> > r;

 public:
  vector<vector<string> > partition(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    r.clear();
    vector<string> row;
    partition(s, row, 0);
    return r;
  }
  void partition(string s, vector<string>& row, int start) {
    if (start == s.size()) {
      r.push_back(row);
      return;
    }
    for (int end = start; end < s.size(); end++) {
      int i = start, j = end;
      bool palindrome = true;
      while (i < j) {
        if (s[i] != s[j]) {
          palindrome = false;
          break;
        }
        i++;
        j--;
      }
      if (palindrome) {
        row.push_back(s.substr(start, end - start + 1));
        partition(s, row, end + 1);
        row.pop_back();
      }
    }
  }
};
