class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> row;
    row.push_back(1);
    if (rowIndex == 0) {
      return row;
    }
    for (int i = 1; i <= rowIndex; i++) {
      vector<int> old_row(row);
      row.clear();
      row.push_back(1);
      for (int j = 0; j < old_row.size() - 1; j++) {
        row.push_back(old_row[j] + old_row[j + 1]);
      }
      row.push_back(1);
    }
    return row;
  }
};
