#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  void flatten(TreeNode* root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (!root)
      return;
    flattenWithTail(root);
  }

 private:
  // Return tail node
  TreeNode* flattenWithTail(TreeNode* root) {
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    root->left = NULL; // Don't forget to set left child NULL.
    TreeNode* cur = root;
    if (left) {
      cur->right = left;
      cur = flattenWithTail(left);
    }
    if (right) {
      cur->right = right;
      cur = flattenWithTail(right);
    }
    return cur;
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  Solution s;
  s.flatten(root);
}
