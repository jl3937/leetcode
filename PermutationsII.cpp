class Solution {
  vector<vector<int> > permute(vector<int>& num, vector<bool>& used) {
    vector<vector<int> > r;
    for (int i = 0; i < num.size(); i++) {
      if (!used[i]) {
        if (i > 0 && num[i - 1] == num[i] && !used[i - 1])
          continue;
        used[i] = true;
        vector<vector<int> > sub_r = permute(num, used);
        for (int j = 0; j < sub_r.size(); j++) {
          vector<int> p(sub_r[j]);
          p.push_back(num[i]);
          r.push_back(p);
        }
        used[i] = false;
      }
    }
    if (r.empty()) {
      vector<int> p;
      r.push_back(p);
    }
    return r;
  }

 public:
  vector<vector<int> > permuteUnique(vector<int>& num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    sort(num.begin(), num.end());
    vector<bool> used;
    for (int i = 0; i < num.size(); i++) {
      used.push_back(false);
    }
    return permute(num, used);
  }
};
