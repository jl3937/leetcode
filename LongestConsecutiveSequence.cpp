class Solution {
public:
  int longestConsecutive(vector<int> &num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    unordered_map<int, bool> num_map;
    for (int i = 0; i < num.size(); i++) {
      num_map[num[i]] = false;
    }
    int longest = 0;
    for (auto pair : num_map) {
      if (!pair.second) {
        pair.second = true;
        int consecutive_num = 1;
        int val = pair.first + 1;
        auto iter = num_map.begin();
        while ((iter = num_map.find(val++)) != num_map.end()) {
          iter->second = true;
          consecutive_num++;
        }
        val = pair.first - 1;
        while ((iter = num_map.find(val--)) != num_map.end()) {
          iter->second = true;
          consecutive_num++;
        }
        longest = max(longest, consecutive_num);
      }
    }
    return longest;
  }
};
