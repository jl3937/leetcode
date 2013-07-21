class Solution {
public:
  string getPermutation(int n, int k) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    bool used[9];
    memset(used, 0, sizeof(used));
    return getPermutation(n, k, used);
  }
  string getPermutation(int n, int k, bool* used) {
    if (n == 0)
      return "";
    string r;
    int num = 1;
    for (int i = 1; i < n; i++) {
      num *= i;
    }
    int i = 0;
    while(used[i]) {
      i++;
    }
    while (k > num) {
      k -= num;
      i++;
      while(used[i]) {
        i++;
      }
    }
    used[i] = true;
    r = '1' + i;
    
    return r + getPermutation(n - 1, k, used);
  }
};