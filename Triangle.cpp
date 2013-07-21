class Solution {
 public:
  // element in triangle may be negative!!
  int minimumTotal(vector<vector<int> >& triangle) {
    int total[512];
    int old_total[512];
    total[0] = triangle[0][0];
    int n = triangle.size();
    for (int i = 1; i < n; i++) {
      memcpy(old_total, total, sizeof(total));
      for (int j = 0; j <= i; j++) {
        if (j == 0) {
          total[0] = old_total[0] + triangle[i][0];
        } else if (j == i) {
          total[j] = old_total[j - 1] + triangle[i][j];
        } else {
          total[j] = min(old_total[j - 1], old_total[j]) + triangle[i][j];
        }
      }
    }

    int min = total[0];
    for (int i = 1; i < n; i++) {
      if (total[i] < min) {
        min = total[i];
      }
    }
    return min;
  }
};
