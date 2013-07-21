class Solution {
 public:
  vector<int> findSubstring(string S, vector<string>& L) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> r;
    map<string, int> l;
    int step = L[0].length();
    int m = S.length();
    int n = L.size() * step;

    for (int i = 0; i < L.size(); i++) {
      if (l.count(L[i]) == 0) {
        l[L[i]] = 1;
      } else {
        l[L[i]]++;
      }
    }
    for (int i = 0; i < step; i++) {
      map<string, int> cur = l;
      int start = i;
      for (int j = i; j + step - 1 < m; j += step) {
        if (start + n == j) {
          string s = S.substr(start, step);
          cur[s]++;
          start += step;
        }
        string s = S.substr(j, step);
        if (cur.count(s) && cur[s] > 0) {
          cur[s]--;
          if (start + n == j + step) {
            r.push_back(start);
          }
        } else {
          while (true) {
            string s_head = S.substr(start, step);
            start += step;
            if (s_head == s) {
              break;
            }
            cur[s_head]++;
          }
        }
      }
    }
    return r;
  }
};
