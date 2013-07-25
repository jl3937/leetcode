class Solution {
 public:
  int largestRectangleArea(vector<int>& height) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    stack<int> s;  // indexes for increasing bars
    int max = 0;
    height.push_back(0);
    for (int i = 0; i < height.size();) {
      if (s.empty() || height[i] >= height[s.top()]) {
        s.push(i);
        i++;
      } else {
        int start = s.top();
        s.pop();
        int area = (s.empty() ? i : (i - s.top() - 1)) * height[start];
        if (area > max)
          max = area;
      }
    }
    return max;
  }
};
