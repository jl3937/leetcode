class Solution {
 public:
  int minCut(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> cut;
    cut.resize(s.size() + 1);
    cut[0] = -1;
    for (int end = 0; end < s.size(); end++) {
      int min = INT_MAX;
      for (int start = end; start >= 0; start--) {
        if (cut[start] + 1 >= min)
          continue;
        int i = start, j = end;
        bool palindrome = true;
        while (i < j) {
          if (s[i] != s[j]) {
            palindrome = false;
            break;
          }
          i++;
          j--;
        }
        if (palindrome) {
          min = cut[start] + 1;
          if (min == 0)
            break;
        }
      }
      cut[end + 1] = min;
    }
    return cut[s.size()];
  }
};
