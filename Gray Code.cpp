class Solution {
public:
  vector<int> grayCode(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> r;
    if (n == 0) {
      r.push_back(0);
      return r;
    }
    vector<int> sub = grayCode(n - 1);
    for (int i = 0; i < sub.size(); i++) {
      r.push_back(sub[i]);
    }
    for (int i = sub.size() - 1; i >= 0; i--) {
      r.push_back(pow(2, (n - 1)) + sub[i]);
    }
    return r;
  }
};