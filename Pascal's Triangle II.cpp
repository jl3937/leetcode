class Solution {
public:
  vector<int> getRow(int rowIndex) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> r(rowIndex + 1);
    r[0] = 1;
    if (rowIndex == 0)
      return r;
    for (int i = 1; i <= rowIndex; i++) {
      r[i] = 1;
      for (int j = i - 1; j >= 1; j--) {
        r[j] += r[j - 1];
      }
    }
    return r;
  }
};
