class Solution {
 public:
  int lengthOfLastWord(const char* s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int i = 0;
    int count = 0;
    int last_count = 0;
    while (s[i]) {
      if (s[i] == ' ') {
        if (count) {
          last_count = count;
        }
        count = 0;
      } else {
        count++;
      }
      i++;
    }
    if (count)
      last_count = count;
    return last_count;
  }
};
