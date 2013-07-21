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
    
    int dup = 1;
    int i = n - 2;
    int val = S[n - 1];
    while (i >= 0 && S[i] == val) {
      dup++;
      i--;
    }
    vector<vector<int> > subr = subsets(S, i + 1);
    for (int i = 0; i < subr.size(); i++) {
      for (int j = 0; j <= dup; j++) {
        vector<int> subset(subr[i]);
        for (int k = 0; k < j; k++) {
          subset.push_back(val);
        }
        r.push_back(subset);
      }
    }
    return r;
  }
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    sort(S.begin(), S.end());
    return subsets(S, S.size());
  }
};