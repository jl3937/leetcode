class Solution {
public:
  vector<vector<int> > fourSum(vector<int> &num, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > r;
    if (num.size() < 4) {
      return r;
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size() - 3; i++) {
      if (i > 0 && num[i] == num[i - 1]) {
        continue;
      }
      for (int j = i + 1; j < num.size() - 2; j++) {
        if (j > i + 1 && num[j] == num[j - 1]) {
          continue;
        }
        int k = j + 1;
        int l = num.size() - 1;
        while (k < l) {
          int sum = num[i] + num[j] + num[k] + num[l];
          if (sum == target) {
            vector<int> quadruplet;
            quadruplet.push_back(num[i]);
            quadruplet.push_back(num[j]);
            quadruplet.push_back(num[k]);
            quadruplet.push_back(num[l]);
            r.push_back(quadruplet);
            k++;
            while (num[k - 1] == num[k]) {
              k++;
            }
            l--;
            while(num[l + 1] == num[l]) {
              l--;
            }
          } else if (sum > target) {
            l--;
          } else {
            k++;
          }
        }
      }
    }
  }
};