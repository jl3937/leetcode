struct record{
  int count[26];
  int index;
};

bool compare(record r1, record r2) {
  for (int i = 0; i < 26; i++) {
    if (r1.count[i] < r2.count[i]) {
      return true;
    }
    if (r1.count[i] > r2.count[i]) {
      return false;
    }
  }
  return false;
}

bool equal(record r1, record r2) {
  for (int i = 0; i < 26; i++) {
    if (r1.count[i] != r2.count[i]) {
      return false;
    }
  }
  return true;
}

class Solution {
public:
  vector<string> anagrams(vector<string> &strs) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<string> r;
    vector<record> RecordList;
    for (int i = 0; i < strs.size(); i++) {
      record r;
      r.index = i;
      for (int i = 0; i < 26; i++) {
        r.count[i] = 0;
      }
      for (int j = 0; j < strs[i].length(); j++) {
        r.count[strs[i][j] - 'a']++;
      }
      RecordList.push_back(r);
    }
    sort(RecordList.begin(), RecordList.end(), compare);
    record cur = RecordList[0];
    int first = true;
    for (int i = 1; i < RecordList.size(); i++) {
      if (equal(RecordList[i], cur)) {
        if (first) {
          r.push_back(strs[cur.index]);
          first = false;
        }
        r.push_back(strs[RecordList[i].index]);
      } else {
        cur = RecordList[i];
        first = true;
      }
    }
    return r;
  }
};
