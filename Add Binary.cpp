class Solution {
public:
  string addBinary(string a, string b) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    string c = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0) {
      int sum = carry;
      if (i >= 0) {
        sum += a[i] - '0';
        i--;
      }
      if (j >= 0) {
        sum += b[j] - '0';
        j--;
      }
      carry = sum / 2;
      if (sum % 2) {
        c = "1" + c;
      } else {
        c = "0" + c;
      }
    }
    if (carry) {
      c = "1" + c;
    }
    return c;
  }
};