class Solution {
public:
  string minWindow(string S, string T) {
    // for each ascii char, compute the counts in T
    int count[256];
    memset(count, 0, sizeof(count));
    int non_zero = 0;
    for (int i = 0; i < T.size(); i++) {
      if (count[T[i]] == 0)
        non_zero++;
      count[T[i]]++;
    }
    
    int start = 0;
    int min_start = 0;
    int min_len = 0;
    for (int i = 0; i < S.size(); i++) {
      count[S[i]]--;
      
      // phase one: find a substring covering T
      if (count[S[i]] == 0) {
        non_zero--;
      }
      
      // phase two: while ensuring covering T, move the start pointer
      if (non_zero == 0) {
        while (count[S[start]] < 0) {
          count[S[start]]++;
          start++;
        }
        int len = i - start + 1;
        if (min_len == 0 || len < min_len) {
          min_start = start;
          min_len = len;
        }
      }
    }
    return S.substr(min_start, min_len);
  }
};