class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int n = prices.size();
    vector<int> front;
    front.resize(n);
    int min = INT_MAX;
    int profit = 0;
    for (int i = 0; i < n; i++) {
      if (prices[i] < min)
        min = prices[i];
      if (prices[i] - min > profit)
        profit = prices[i] - min;
      front[i] = profit;
    }
    
    vector<int> back;
    back.resize(n);
    int max = INT_MIN;
    profit = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (prices[i] > max)
        max = prices[i];
      if (max - prices[i] > profit)
        profit = max - prices[i];
      back[i] = profit;
    }
    int max_profit = 0;
    for (int i = 0; i < n; i++) {
      if (front[i] + back[i] > max_profit)
        max_profit = front[i] + back[i];
    }
    return max_profit;
  }
};