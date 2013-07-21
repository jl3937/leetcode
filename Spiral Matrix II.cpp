class Solution {
public:
  vector<vector<int> > generateMatrix(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > r;
    for (int i = 0; i < n; i++) {
      vector<int> row;
      for (int j = 0; j < n; j++) {
        row.push_back(0);
      }
      r.push_back(row);
    }
    int x = 0, y = 0;
    int cur = 0;
    int l = n + 1;
    
    while (cur != n * n) {
      l -= 2;
      if (l == 0) {
        r[x][y] = ++cur;
        break;
      }
      for (int d = 0; d < 4; d++) {
        for (int s = 0; s < l; s++) {
          r[x][y] = ++cur;
          if (d == 3 && s == l - 1)
            y++;
          else if (d == 0) {
            y++;
          } else if (d == 1) {
            x++;
          } else if (d == 2) {
            y--;
          } else if (d == 3) {
            x--;
          }
        }
      }
    }
    return r;
  }
};
