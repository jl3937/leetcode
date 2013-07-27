class Solution {
public:
  int removeElement(int A[], int n, int elem) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int tail = n - 1;
    for (int i = 0; i <= tail; i++) {
      if (A[i] == elem) {
        swap(A[i], A[tail]);
        tail--;
        i--;
      }
    }
    return tail + 1;
  }
};
