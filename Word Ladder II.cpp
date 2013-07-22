class Solution {
  vector<vector<int> > adj;  // prev node in shortest path
  vector<string> dict_vector;
  map<string, int> dict_map;

 public:
  vector<vector<string> > findLadders(string start,
                                      string end,
                                      unordered_set<string>& dict) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int n = dict.size();
    int len = (*dict.begin()).size();

    dict_vector.clear();
    dict_vector.resize(n);
    dict_map.clear();
    int i = 0;
    for (const auto& word : dict) {
      dict_vector[i] = word;
      dict_map[word] = i++;
    }

    unordered_set<string> visited;
    set<string> level[2];
    bool l = false;
    level[0].insert(start);
    visited.insert(start);
    bool found = false;
    int d = 1;

    adj.clear();
    adj.resize(n);
    while (!found && !level[l].empty()) {
      for (const auto& word : level[l]) {
        string s = word;
        int prev = dict_map[s];
        for (int j = 0; j < len; j++) {
          int orig_ch = s[j];
          for (int ch = 'a'; ch <= 'z'; ch++) {
            if (orig_ch != ch) {
              s[j] = ch;
              if (!visited.count(s)) {
                if (dict.count(s)) {
                  if (s == end)
                    found = true;
                  adj[dict_map[s]].push_back(prev);
                  level[!l].insert(s);
                }
              }
            }
          }
          s[j] = orig_ch;
        }
      }
      for (const auto& word : level[!l]) {
        visited.insert(word);
      }
      level[l].clear();
      l = !l;
      d++;
      if (d == n)
        break;
    }
    int e = dict_map[end];
    if (adj[e].empty()) {
      vector<vector<string> > r;
      return r;
    }
    return findPaths(dict, e);
  }

  vector<vector<string> > findPaths(unordered_set<string>& dict, int e) {
    vector<vector<string> > r;
    if (adj[e].empty()) {
      vector<string> path;
      path.push_back(dict_vector[e]);
      r.push_back(path);
      return r;
    }
    for (int i = 0; i < adj[e].size(); i++) {
      vector<vector<string> > paths = findPaths(dict, adj[e][i]);
      for (int j = 0; j < paths.size(); j++) {
        paths[j].push_back(dict_vector[e]);
        r.push_back(paths[j]);
      }
    }
    return r;
  }
};
