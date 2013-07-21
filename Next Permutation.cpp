class Solution {
 public:
  // Return true if permutate successfully.
  bool nextPermutation(vector<int>& num, int start) {
    if (start == num.size())
      return false;
    if (nextPermutation(num, start + 1))
      return true;
    int i;
    for (i = num.size() - 1; i > start; i--) {
      if (num[i] > num[start]) {
        swap(num[i], num[start]);
        int left = start + 1, right = num.size() - 1;
        while (left < right) {
          swap(num[left], num[right]);
          left++;
          right--;
        }
        break;
      }
    }
    return i != start;
  }
  void nextPermutation(vector<int>& num) {
    if (nextPermutation(num, 0))
      return;
    int left = 0, right = num.size() - 1;
    while (left < right) {
      swap(num[left], num[right]);
      left++;
      right--;
    }
  }
};
