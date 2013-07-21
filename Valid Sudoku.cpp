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

  bool isValidSudoku(vector<vector<char> > &board) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          if (check(board, i, j) == 0)
            return false;
        }
      }
    }
    return true;
  }
};
