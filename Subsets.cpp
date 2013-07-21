class Solution {
public:
  vector<vector<int> > subsets(vector<int> &S, int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > r;
    if (n == 0) {
      vector<int> subset;
      r.push_back(subset);
      return r;
    }
    vector<vector<int> > subr = subsets(S, n - 1);
    for (int i = 0; i < subr.size(); i++) {
      r.push_back(subr[i]);
      vector<int> subset(subr[i]);
      subset.push_back(S[n - 1]);
      r.push_back(subset);
    }
    return r;
  }
  vector<vector<int> > subsets(vector<int> &S) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    sort(S.begin(), S.end());
    return subsets(S, S.size());
  }
};