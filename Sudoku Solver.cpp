class Solution {
public:
  bool check(vector<vector<char> > &board, int r, int c) {
    for (int i = 0; i < 9; i++) {
      if (i != c && board[r][i] == board[r][c])
        return false;
      if (i != r && board[i][c] == board[r][c])
        return false;
    }
    for (int i = r / 3 * 3; i < (r / 3 + 1) * 3; i++)
      for (int j = c / 3 * 3; j < (c / 3 + 1) * 3; j++)
        if (!(i == r && j == c) && board[i][j] == board[r][c])
          return false;
    return true;
  }
  bool hasValid(vector<vector<char> > &board, int r, int c) {
    if (r == 9 && c == 0) {
      return true;
    }
    int nr, nc;
    if (c == 8) {
      nr = r + 1;
      nc = 0;
    } else {
      nr = r;
      nc = c + 1;
    }
    if (board[r][c] == '.') {
      for (int i = 0; i < 9; i++) {
        board[r][c] = '1' + i;
        if (check(board, r, c)) {
          if (hasValid(board, nr, nc))
            return true;
        }
      }
      board[r][c] = '.';
      return false;
    }
    return hasValid(board, nr, nc);
  }
  void solveSudoku(vector<vector<char> > &board) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    hasValid(board, 0, 0);
  }
};
