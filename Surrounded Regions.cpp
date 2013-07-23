int x[] = {0, 0, -1, 1};
int y[] = {-1, 1, 0, 0};
class Solution {
 public:
  void solve(vector<vector<char> >& board) {
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
  bool reachEdge(vector<vector<char> >& board, int i, int j) {
    if (board[i][j] != 'O')
      return false;
    queue<pair<int, int> > q;
    bool reach = false;

    board[i][j] = '.';
    q.push(make_pair(i, j));
    if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
      reach = true;
    while (!q.empty()) {
      pair<int, int> pos = q.front();
      i = pos.first;
      j = pos.second;
      q.pop();
      for (int d = 0; d < 4; d++) {
        if (i + x[d] >= 0 && i + x[d] < m && j + y[d] >= 0 && j + y[d] < n &&
            board[i + x[d]][j + y[d]] == 'O') {
          board[i + x[d]][j + y[d]] = '.';
          if (i + x[d] == 0 || i + x[d] == m - 1 || j + y[d] == 0 ||
              j + y[d] == n - 1)
            reach = true;
          q.push(make_pair(i + x[d], j + y[d]));
        }
      }
    }
    return reach;
  }

  void flip(vector<vector<char> >& board, int i, int j) {
    queue<pair<int, int> > q;
    bool reach = false;

    board[i][j] = 'X';
    q.push(make_pair(i, j));
    while (!q.empty()) {
      pair<int, int> pos = q.front();
      i = pos.first;
      j = pos.second;
      q.pop();
      for (int d = 0; d < 4; d++) {
        if (i + x[d] >= 0 && i + x[d] < m && j + y[d] >= 0 && j + y[d] < n &&
            board[i + x[d]][j + y[d]] == '.') {
          board[i + x[d]][j + y[d]] = 'X';
          q.push(make_pair(i + x[d], j + y[d]));
        }
      }
    }
  }
};
