class Solution {
public:
  int minimumTotal(vector<vector<int> > &triangle) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (triangle.empty())
      return 0;
    int n = triangle.size();
    vector<int> total(triangle[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j <= i; j++) {
        total[j] = triangle[i][j] + min(total[j], total[j + 1]);
      }
    }
    return total[0];
  }
};
