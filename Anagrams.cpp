class Solution {
public:
  vector<string> anagrams(vector<string> &strs) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<string> r;
    map<string, vector<string> > anagrams_map;
    for (int i = 0; i < strs.size(); i++) {
      string sorted_str = strs[i];
      sort(sorted_str.begin(), sorted_str.end());
      anagrams_map[sorted_str].push_back(strs[i]);
    }
    for (auto map_iter = anagrams_map.begin(); map_iter != anagrams_map.end();
         map_iter++) {
      vector<string> &anagrams_vec = map_iter->second;
      if (anagrams_vec.size() == 1)
        continue;
      for (int i = 0; i < anagrams_vec.size(); i++) {
        r.push_back(anagrams_vec[i]);
      }
    }
    return r;
  }
};
