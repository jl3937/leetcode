class Solution {
public:
  vector<vector<int> > generate(int numRows) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > r(numRows);
    if (numRows == 0)
      return r;
    r[0].push_back(1);
    for (int i = 1; i < numRows; i++) {
      r[i].push_back(1);
      for (int j = 0; j < i - 1; j++) {
        r[i].push_back(r[i - 1][j] + r[i - 1][j + 1]);
      }
      r[i].push_back(1);
    }
    return r;
  }
};
