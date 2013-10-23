class Solution {
public:
  int candy(vector<int> &ratings) {
    // Note: The Solution object is instantiated only once and is reused by each
    // test case.
    int n = ratings.size();
    vector<int> candies(n);
    candies[0] = 1;
    for (int i = 1; i < n; i++) {
      if (ratings[i] > ratings[i - 1]) {
        candies[i] = candies[i - 1] + 1;
      } else {
        candies[i] = 1;
      }
    }
    int sum = candies[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1]) {
        candies[i] = max(candies[i], candies[i + 1] + 1);
      }
      sum += candies[i];
    }
    return sum;
  }
};
