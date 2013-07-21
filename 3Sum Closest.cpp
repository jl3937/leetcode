class Solution {
public:
  int threeSumClosest(vector<int> &num, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    sort(num.begin(), num.end());
    int minDiff;
    bool first = true;
    for (int i = 0; i < num.size() - 2; i++) {
      if (i > 0 && num[i] == num[i - 1]) {
        continue;
      }
      int j = i + 1;
      int k = num.size() - 1;
      while (j < k) {
        int sum = num[i] + num[j] + num[k];
        if (sum == target) {
          return sum;
        } else if (sum > target) {
          k--;
        } else {
          j++;
        }
        if (first) {
          minDiff = sum - target;
          first = false;
        } else if (abs(sum - target) < abs(minDiff)) {
          minDiff = sum - target;
        }
      }
    }
    return minDiff + target;
  }
};