class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > r;
    if (num.size() < 3) {
      return r;
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size() - 2; i++) {
      if (i > 0 && num[i] == num[i - 1]) {
        continue;
      }
      int j = i + 1;
      int k = num.size() - 1;
      while (j < k) {
        int sum = - num[j] - num[k];
        if (sum == num[i]) {
          vector<int> triple;
          triple.push_back(num[i]);
          triple.push_back(num[j]);
          triple.push_back(num[k]);
          r.push_back(triple);
          j++;
          while (num[j - 1] == num[j]) {
            j++;
          }
          k--;
          while(num[k + 1] == num[k]) {
            k--;
          }
        } else if (sum < num[i]) {
          k--;
        } else {
          j++;
        }
      }
    }
  }
};
