class Solution {
public:
  bool isNumber(const char *s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int i = 0;
    bool hasDot = false;
    bool hasNum = false;
    while (s[i] == ' ') {
      i++;
    }
    if (s[i] == '+' || s[i] == '-')
      i++;
    if (s[i] == 'e')
      return false;
    while (s[i] != '\0') {
      if (s[i] <= '9' && s[i] >= '0') {
        hasNum = true;
      } else if (s[i] == 'e') {
        if (!hasNum)
          return false;
        i++;
        if (s[i] == '+' || s[i] == '-')
          i++;
        hasNum = false;
        while (s[i] != '\0') {
          if (s[i] <= '9' && s[i] >= '0') {
            hasNum = true;
          } else if (s[i] == 'e') {
            return false;
          } else if (s[i] == '.') {
            return false;
          } else if (s[i] == ' ') {
            while (s[i] == ' ') {
              i++;
            }
            if (s[i] != '\0') {
              return false;
            }
            return hasNum;
          } else {
            return false;
          }
          i++;
        }
        return hasNum;
      } else if (s[i] == '.') {
        if (hasDot) {
          return false;
        } else {
          hasDot = true;
        }
      } else if (s[i] == ' ') {
        while (s[i] == ' ') {
          i++;
        }
        if (s[i] != '\0') {
          return false;
        }
        return hasNum;
      } else {
        return false;
      }
      i++;
    }
    return hasNum;
  }
};