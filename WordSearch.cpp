int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};
class Solution {
  int m, n;
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
            if (exist(board, word, i, j, 0)) {
              return true;
            }
          }
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word, int i, int j, int pos) {
      if (pos == word.size())
        return true;
      if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[pos])
        return false;
      char ch = board[i][j];
      board[i][j] = '.';
      for (int d = 0; d < 4; d++) {
        if (exist(board, word, i + x[d], j + y[d], pos + 1)) {
          return true;
        }
      }
      board[i][j] = ch;
      return false;
    }
};
