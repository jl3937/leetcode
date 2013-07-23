int x[] = {0, 0, -1, 1};
int y[] = {-1, 1, 0, 0};
class Solution {
public:
  void solve(vector<vector<char>> &board) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    m = board.size();
    if (m == 0)
      return;
    n = board[0].size();
    if (n == 0)
      return;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'O' && !reachEdge(board, i, j)) {
          flip(board, i, j);
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == '.') {
          board[i][j] = 'O';
        }
      }
    }
  }
private:
  int m;
  int n;
  bool reachEdge(vector<vector<char>> &board, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
      return false;
    board[i][j] = '.';
    bool reach = false;
    for (int d = 0; d < 4; d++) {
      if (reachEdge(board, i + x[d], j + y[d])) {
        reach = true;
      }
    }
    if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
      reach = true;;
    return reach;
  }
  
  void flip(vector<vector<char>> &board, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != '.')
      return;
    board[i][j] = 'X';
    for (int d = 0; d < 4; d++) {
      flip(board, i + x[d], j + y[d]);
    }
  }
};
