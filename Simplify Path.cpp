class Solution {
public:
  string simplifyPath(string path) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    string r;
    int i = 0;
    path = path + '/';
    while (i < path.length()) {
      if (i + 1 < path.length() && path[i] == '.' && path[i + 1] == '.') {
        r += '.';
        r += '.';
        i += 2;
      } else if (i + 1 < path.length() && path[i] == '.' && path[i + 1] == '/') {
        i += 2;
      } else {
        r += path[i];
        i++;
      }
    }
    
    path = r;
    r = "";
    
    vector<string> names;
    i = 0;
    while (i < path.length()) {
      if (path[i] == '/') {
        r += '/';
        while (i < path.length() && path[i] == '/') {
          i++;
        }
      } else if (path[i] == '.' && path[i + 1] == '.') {
        if (!names.empty()) {
          names.pop_back();
        }
        i += 2;
      } else {
        string name;
        while (i < path.length() && path[i] != '/') {
          name += path[i];
          i++;
        }
        names.push_back(name);
      }
    }
    
    r = "";
    for (int i = 0; i < names.size(); i++) {
      r += "/" + names[i];
    }
    if (r == "") {
      r = "/";
    }
    
    return r;
  }
};