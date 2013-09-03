int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
class Solution {
  int m;
  int n;
  void colorEdge(vector<vector<char> > &board, int row, int col) {
    if (board[row][col] != 'O')
      return;
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    board[row][col] = '.';
    while(!q.empty()) {
      int i = q.front().first, j = q.front().second;
      q.pop();
      for (int d = 0; d < 4; d++) {
        int ii = i + dx[d], jj = j + dy[d];
        if (ii >= 0 && ii < m && jj >= 0 && jj < n && board[ii][jj] == 'O') {
          board[ii][jj] = '.';
          q.push(make_pair(ii, jj));
        }
      }
    }
  }
public:
  void solve(vector<vector<char> > &board) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    m = board.size();
    if (m == 0)
      return;
    n = board[0].size();
    // starting from the edges
    for (int i = 0; i < m; i++) {
      colorEdge(board, i, 0);
      colorEdge(board, i, n - 1);
    }
    for (int i = 1; i < n - 1; i++) {
      colorEdge(board, 0, i);
      colorEdge(board, m - 1, i);
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == '.') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }
};
