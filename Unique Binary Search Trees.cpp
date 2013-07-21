class Solution {
public:
  int numTrees(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> c;
    c.push_back(1);
    c.push_back(1);
    for (int i = 2; i <= n; i++) {
      int sum = 0;
      for (int j = 0; j < i; j++) {
        sum += c[j] * c[i - 1 - j];
      }
      c.push_back(sum);
    }
    return c[n];
  }
};