/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (!root)
      return true;
    if (!root->left && !root->right) {
      root->val = 1;
      return true;
    }
    int left_height = 0, right_height = 0;
    if (root->left) {
      if (!isBalanced(root->left))
        return false;
      else
        left_height = root->left->val;
    }
    if (root->right) {
      if (!isBalanced(root->right))
        return false;
      else
        right_height = root->right->val;
    }
    if (left_height - right_height > 1 || left_height - right_height < -1)
      return false;
    root->val = max(left_height, right_height) + 1;
    return true;
  }
};
