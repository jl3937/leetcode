class Solution {
public:
  string multiply(string num1, string num2) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (num1 == "0" || num2 == "0")
      return "0";
    if (num1.length() < num2.length())
      return multiply(num2, num1);
    int sum[1024];
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < num2.length(); i++) {
      for (int j = 0; j < num1.length(); j++) {
        int v2 = num2[num2.length() - 1 - i] - '0';
        int v1 = num1[num1.length() - 1 - j] - '0';
        sum[i + j] += v1 * v2;
      }
    }
    for (int i = 0; i < num1.length() + num2.length() - 1; i++) {
      sum[i + 1] += sum[i] / 10;
      sum[i] = sum[i] % 10;
    }
    string r = "";
    if (sum[num1.length() + num2.length() - 1] != 0) {
      r += (sum[num1.length() + num2.length() - 1] + '0');
    }
    for (int i = num1.length() + num2.length() - 2; i >= 0; i--) {
      r += (sum[i] + '0');
    }
    return r;
  }
};