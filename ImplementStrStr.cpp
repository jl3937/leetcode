class Solution {
public:
  char *strStr(char *haystack, char *needle) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    for (int i = 0; i == 0 || haystack[i] != '\0'; i++) {
      int j;
      for (j = 0; needle[j] != '\0'; j++) {
        if (haystack[i + j] != needle[j])
          break;
      }
      if (needle[j] == '\0')
        return haystack + i;
    }
    return NULL;
  }
};
