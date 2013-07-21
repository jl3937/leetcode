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
   
    int num = 0;
    int i = pos;
    while (i < candidates.size() && candidates[i] == candidates[pos]) {
      i++;
    }
    combinationSum(candidates, target, c, i);
    while (pos < i && candidates[pos] <= target) {
      num++;
      target -= candidates[pos];
      c.push_back(candidates[pos]);
      combinationSum(candidates, target, c, i);
      pos++;
    }
    for (int i = 0; i < num; i++) {
      c.pop_back();
    }
  }
  vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    r.clear();
    vector<int> c;
    sort(num.begin(), num.end());
    combinationSum(num, target, c, 0);
    return r;
  }
};