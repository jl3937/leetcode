class Solution {
 public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > r;
    if (numRows == 0) {
      return r;
    }
    vector<int> row;
    row.push_back(1);
    r.push_back(row);
    if (numRows == 1) {
      return r;
    }
    for (int i = 1; i < numRows; i++) {
      vector<int> old_row(row);
      row.clear();
      row.push_back(1);
      for (int j = 0; j < old_row.size() - 1; j++) {
        row.push_back(old_row[j] + old_row[j + 1]);
      }
      row.push_back(1);
      r.push_back(row);
    }
    return r;
  }
};
