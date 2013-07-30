class Solution {
public:
  char *strStr(char *haystack, char *needle) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (needle[0] == 0)
        return haystack;
    int p[40000];
    p[0] = -1;
    for (int i = 0; needle[i] != '\0'; i++) {
      int j = p[i];
      while (j != -1 && needle[i] != needle[j]) {
        j = p[j];
      }
      p[i + 1] = j + 1;
    }
    int i = 0, j = 0;
    while (i == 0 || haystack[i + j] != '\0') {
      while (j != -1 && haystack[i + j] != needle[j]) {
        i += j - p[j];
        j = p[j];
      }
      if (needle[j + 1] == '\0')
        return haystack + i;
      j++;
    }
    return NULL;
  }
};
