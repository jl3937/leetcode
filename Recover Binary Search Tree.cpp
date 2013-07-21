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
  TreeNode* prev = NULL;
  TreeNode* large = NULL;
  TreeNode* small = NULL;
  void visitTree(TreeNode* root) {
    if (root == NULL)
      return;
    visitTree(root->left);
    if (prev) {
      if (root->val < prev->val) {
        if (!large) {
          large = prev;
          small = root;
        } else {
          small = root;
        }
      }
    }
    prev = root;
    visitTree(root->right);
  }
 public:
  void recoverTree(TreeNode* root) {
    large = NULL;
    small = NULL;
    prev = NULL;
    visitTree(root);
    swap(small->val, large->val);
  }
};
