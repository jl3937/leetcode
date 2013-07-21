class Solution {
vector<vector<string> > r;
  bool check(vector<string> q, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
      if (q[i][col] == 'Q')
        return false;
      int left = col - row + i;
      if (left >= 0 && left < n && q[i][left] == 'Q')
        return false;
      int right = row - i + col;
      if (right >= 0 && right < n && q[i][right] == 'Q')
        return false;
    }
    return true;
  }
  void put(vector<string> q, int row, int n) {
    if (row == n) {
      vector<string> vq;
      for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < n; j++) {
          s = s + q[i][j];
        }
        vq.push_back(s);
      }
      r.push_back(vq);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (q[row][i] == '.') {
        q[row][i] = 'Q';
        if (check(q, row, i, n)) {
          put(q, row + 1, n);
        }
        q[row][i] = '.';
      }
    }
  }
public:
  vector<vector<string> > solveNQueens(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    r.clear();
    vector<string> q;
    for (int i = 0; i < n; i++) {
      string s = "";
      for (int j = 0; j < n; j++) {
        s = s + ".";
      }
      q.push_back(s);
    }
    put(q, 0, n);
    return r;
  }
};