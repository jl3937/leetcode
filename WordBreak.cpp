class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    // Note: The Solution object is instantiated only once and is reused by each
    // test case.
    vector<bool> match(s.size() + 1);
    match[0] = true;
    for (int i = 1; i <= s.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (match[j] && dict.count(s.substr(j, i - j))) {
          match[i] = true;
          break;
        }
      }
    }
    return match[s.size()];
  }
};
