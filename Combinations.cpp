class Solution {
public:
  vector<vector<int> > combine(int n, int k) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > r;
    if (k > n)
      return r;
    if (k == 0) {
      vector<int> row;
      r.push_back(row);
      return r;
    }
    for (int i = 1; i <= n; i++) {
      vector<vector<int> > sub_r = combine(i - 1, k - 1);
      for (int j = 0; j < sub_r.size(); j++) {
        vector<int> row(sub_r[j]);
        row.push_back(i);
        r.push_back(row);
      }
    }
    return r;
  }
};
