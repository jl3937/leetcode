class Solution {
  vector<vector<int> > r;
public:
  void combinationSum(vector<int> &candidates, int target, vector<int> &c,
                      int pos) {
    if (pos == candidates.size()) {
      if (target == 0) {
        vector<int> vc;
        for (int i = 0; i < c.size(); i++) {
          vc.push_back(c[i]);
        }
        r.push_back(vc);
      }
      return;
    }
    combinationSum(candidates, target, c, pos + 1);
    int num = 0;
    while(candidates[pos] <= target) {
      num++;
      target -= candidates[pos];
      c.push_back(candidates[pos]);
      combinationSum(candidates, target, c, pos + 1);
    }
    for (int i = 0; i < num; i++) {
      c.pop_back();
    }
  }
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    r.clear();
    vector<int> c;
    sort(candidates.begin(), candidates.end());
    combinationSum(candidates, target, c, 0);
    return r;
  }
};