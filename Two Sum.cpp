class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<pair<int, int>> pairs;
    for (int i = 0; i < numbers.size(); i++) {
      pairs.push_back(make_pair(numbers[i], i + 1));
    }
    sort(pairs.begin(), pairs.end());
    int i = 0;
    int j = numbers.size() - 1;
    while (true) {
      if (pairs[i].first + pairs[j].first == target) {
        vector<int> r;
        r.push_back(pairs[i].second);
        r.push_back(pairs[j].second);
        if (r[0] > r[1])
          swap(r[0], r[1]);
        return r;
      } else if (pairs[i].first + pairs[j].first < target) {
        i++;
      } else {
        j--;
      }
    }
  }
};
