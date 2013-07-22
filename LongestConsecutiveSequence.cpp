class Solution {
 public:
  int longestConsecutive(vector<int>& num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    unordered_map<int, bool> A;
    for (int i = 0; i < num.size(); i++) {
      A[num[i]] = false;
    }
    int max_len = 0;
    for (auto iter = A.begin(); iter != A.end(); iter++) {
      if (!iter->second) {
        iter->second = true;
        int len = 1;
        int val = iter->first;
        auto adj = A.begin();
        while ((adj = A.find(--val)) != A.end()) {
          adj->second = true;
          len++;
        }
        val = iter->first;
        while ((adj = A.find(++val)) != A.end()) {
          adj->second = true;
          len++;
        }
        if (len > max_len)
          max_len = len;
      }
    }
    return max_len;
  }
};
