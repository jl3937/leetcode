class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (prices.empty())
      return 0;
    int profit = 0;
    int prev = prices[0];
    int buy_price = prices[0];
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] < prev) {
        profit += prev - buy_price;
        buy_price = prices[i];
      }
      prev = prices[i];
    }
    profit += prev - buy_price;
    return profit;
  }
};