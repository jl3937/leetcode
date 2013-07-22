class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<bool> can_jump(n);
        can_jump[0] = true;
        for (int i = 1; i < n; i++) {
          int j;
          for (j = 0; j < i; j++) {
            if (can_jump[j] && j + A[j] >= i) {
              can_jump[i] = true;
              break;
            }
          }
          if (j == i)
            can_jump[i] = false;
        }
        return can_jump[n - 1];
    }
};
