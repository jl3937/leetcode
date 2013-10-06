class Solution {
  vector<string> r;

public:
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    // Note: The Solution object is instantiated only once and is reused by each
    // test case.
    vector<vector<int> > match(s.size());
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j <= i; j++) {
        if ((j == 0 || !match[j - 1].empty()) &&
            dict.count(s.substr(j, i - j + 1))) {
          match[i].push_back(j);
        }
      }
    }
    r.clear();
    concatenate(s, dict, match, s.size() - 1, "");
    return r;
  }

  void concatenate(string &s, unordered_set<string> &dict,
                   vector<vector<int> > &match, int cur_index, string cur_s) {
    for (int i = 0; i < match[cur_index].size(); i++) {
      int start = match[cur_index][i];
      if (start == 0) {
        r.push_back(s.substr(0, cur_index + 1) + cur_s);
      } else {
        concatenate(s, dict, match, start - 1,
                    " " + s.substr(start, cur_index - start + 1) + cur_s);
      }
    }
  }
};
