class Solution {
public:
  int candy(vector<int> &ratings) {
    // Note: The Solution object is instantiated only once and is reused by each
    // test case.
    vector<int> candies(ratings.size());
    for (int i = 0; i < candies.size(); i++) {
      candies[i] = 1;
    }
    bool change = true;
    while (change) {
      change = false;
      for (int i = 0; i < candies.size(); i++) {
        if (i > 0 && ratings[i] > ratings[i - 1] &&
            candies[i] <= candies[i - 1]) {
          candies[i] = candies[i - 1] + 1;
          change = true;
        }
        if (i < candies.size() - 1 && ratings[i] > ratings[i + 1] &&
            candies[i] <= candies[i + 1]) {
          candies[i] = candies[i + 1] + 1;
          change = true;
        }
      }
    }
    int sum = 0;
    for (int i = 0; i < candies.size(); i++)
      sum += candies[i];
    return sum;
  }
};
