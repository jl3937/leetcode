class Solution {
  int r;
  bool check(bool q[16][16], int row, int col, int n) {
    for (int i = 0; i < row; i++) {
      if (q[i][col])
        return false;
      int left = col - row + i;
      if (left >= 0 && left < n && q[i][left])
        return false;
      int right = row - i + col;
      if (right >= 0 && right < n && q[i][right])
        return false;
    }
    return true;
  }
  void put(bool q[16][16], int row, int n) {
    if (row == n) {
      r++;
      return;
    }
    for (int i = 0; i < n; i++) {
      if (q[row][i] == false) {
        q[row][i] = true;
        if (check(q, row, i, n)) {
          put(q, row + 1, n);
        }
        q[row][i] = false;
      }
    }
  }
public:
  int totalNQueens(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    r = 0;
    bool q[16][16];
    memset(q, 0, sizeof(q));
    put(q, 0, n);
    return r;
  }
};