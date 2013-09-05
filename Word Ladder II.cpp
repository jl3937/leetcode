class Solution {
  vector<vector<string> > r;
  vector<vector<int> > pre; // predecessors in shortest path
  vector<string> dict_vector;
  unordered_map<string, int> dict_map;

public:
  vector<vector<string> > findLadders(string start, string end,
                                      unordered_set<string> &dict) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int n = dict.size();
    dict_vector.clear();
    dict_vector.resize(n);
    dict_map.clear();
    int i = 0;
    for (const auto &word : dict) {
      dict_vector[i] = word;
      dict_map[word] = i++;
    }

    r.clear();
    pre.clear();
    pre.resize(n);
    set<int> level[2];
    vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
      visited[i] = false;
    }
    int start_index = dict_map[start];
    int end_index = dict_map[end];
    level[0].insert(start_index);
    visited[start_index] = true;
    i = 0;
    int len = 1;
    int word_len = (*dict.begin()).size();
    while (!level[i].empty()) {
      for (int orig_index : level[i]) {
        string word = dict_vector[orig_index];
        for (int index = 0; index < word_len; index++) {
          int orig_ch = word[index];
          for (char ch = 'a'; ch <= 'z'; ch++) {
            if (ch != orig_ch) {
              word[index] = ch;
              auto iter = dict_map.find(word);
              if (iter != dict_map.end()) {
                int next_index = iter->second;
                if (!visited[next_index]) {
                  pre[next_index].push_back(orig_index);
                  level[1 - i].insert(next_index);
                }
              }
            }
          }
          word[index] = orig_ch;
        }
      }
      level[i].clear();
      i = 1 - i;
      for (int next_index : level[i]) {
        visited[next_index] = true;
        if (next_index == end_index) {
          level[i].clear();
          break;
        }
      }
      len++;
    }
    vector<string> path(len);
    path[len - 1] = end;
    findPath(path, len - 1, end_index);
    return r;
  }
  void findPath(vector<string> &path, int i, int index) {
    if (i == 0) {
      r.push_back(path);
      return;
    }
    for (int pre_index : pre[index]) {
      path[i - 1] = dict_vector[pre_index];
      findPath(path, i - 1, pre_index);
    }
  }
};
