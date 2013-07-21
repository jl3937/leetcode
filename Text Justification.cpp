class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int L) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<string> r;
    int index = 0;
    while (true) {
      if (index == words.size())
        break;
      int remain = L + 1;
      int begin = index;
      while (true) {
        if (index == words.size()) {
          remain = 0;
          break;
        }
        if (words[index].length() + 1 <= remain) {
          remain -= words[index].length() + 1;
          index++;
        } else {
          break;
        }
      }
      
      int end = index;
      int extra = 0;
      int extram = 0;
      string line = words[begin];
      if (end - begin - 1 != 0) {
        extra = remain / (end - begin - 1);
        extram = remain % (end - begin - 1);
        for (int i = begin + 1; i < end; i++) {
          for (int j = 0; j < extra; j++)
            line += " ";
          if (i - begin - 1 < extram)
            line += " ";
          line += " " + words[i];
        }
      }
      if (line.length() < L) {
        int c = L - line.length();
        for (int i = 0; i < c; i++)
          line += " ";
      }
      r.push_back(line);
    }
    return r;
  }
};
