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
  bool isSymmetric(TreeNode* root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (!root)
      return true;
    return isMirror(root->left, root->right);
  }
  bool isMirror(TreeNode* first, TreeNode* second) {
    if (!first && !second)
      return true;
    if (!first || !second)
      return false;
    if (first->val != second->val)
      return false;
    return isMirror(first->left, second->right) &&
           isMirror(first->right, second->left);
  }
};
