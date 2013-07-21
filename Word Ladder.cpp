bool visited[10000];
class Solution {
 public:
  int ladderLength(string start, string end, unordered_set<string>& dict) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (start == end)
      return 1;
    int n = dict.size();
    int len = (*dict.begin()).size();
    queue<string> q;
    unordered_set<string> visited;
    visited.insert(start);
    q.push(start);
    int d = 1;
    int w = 0;
    int last_w = 1;
    while (!q.empty()) {
      string cur_s = q.front();
      q.pop();
      last_w--;
      for (int i = 0; i < len; i++) {
        int orig_ch = cur_s[i];
        for (int ch = 'a'; ch <= 'z'; ch++) {
          if (ch != orig_ch) {
            cur_s[i] = ch;
            if (!visited.count(cur_s) && dict.count(cur_s)) {
              if (cur_s == end) {
                return d + 1;
              }
              visited.insert(cur_s);
              q.push(cur_s);
              w++;
            }
          }
        }
        cur_s[i] = orig_ch;
      }
      if (last_w == 0) {
        last_w = w;
        w = 0;
        d++;
        if (d == n + 1)
          return 0;
      }
    }
    return 0;
  }
};
