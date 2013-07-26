
class Solution {
public:
  void sortColors(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int one_ptr = 0, two_ptr = 0;
    for (int i = 0; i < n; i++) {
      if (A[i] == 0) {
        int tmp = A[i];
        A[i] = A[two_ptr];
        A[two_ptr] = A[one_ptr];
        A[one_ptr] = tmp;
        one_ptr++;
        two_ptr++;
      } else if (A[i] == 1) {
        swap(A[i], A[two_ptr]);
        two_ptr++;
      }
    }
  }
};
