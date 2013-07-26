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
  int cur;
public:
  bool isValidBST(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    cur = INT_MIN;
    return visit(root);
  }
  bool visit(TreeNode *root) {
    if (!root)
      return true;
    if (!visit(root->left))
      return false;
    if (root->val <= cur)
      return false;
    cur = root->val;
    if (!visit(root->right))
      return false;
    return true;
  }
};
