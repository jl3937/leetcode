class Solution {
 public:
  string minWindow(string S, string T) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int m = S.size(), n = T.size();
    int count[256];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < n; i++) {
      count[T[i]]++;
    }
    int min_window = INT_MAX;
    int min_index = -1;
    int match = n;
    int start = 0;
    for (int i = 0; i < m; i++) {
      count[S[i]]--;
      if (count[S[i]] >= 0) {
        match--;
      }
      while (count[S[start]] < 0) {
        count[S[start]]++;
        start++;
      }
      if (match == 0 && i - start + 1 < min_window) {
        min_window = i - start + 1;
        min_index = start;
      }
    }
    if (min_index != -1)
      return S.substr(min_index, min_window);
    return "";
  }
};
