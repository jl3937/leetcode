class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int n = prices.size();
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
      profit += max(prices[i] - prices[i - 1], 0);
    }
    return profit;
  }
};
