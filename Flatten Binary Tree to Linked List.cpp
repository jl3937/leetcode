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
  void flatten(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    flattenWithTail(root);
  }
  TreeNode *flattenWithTail(TreeNode *root) {
    if (!root)
      return NULL;
    TreeNode *left = flattenWithTail(root->left);
    TreeNode *right = flattenWithTail(root->right);
    if (left) {
      left->right = root->right;
      root->right = root->left;
      root->left = NULL; // Don't forget to set left child NULL.
    }
    if (right)
      return right;
    if (left)
      return left;
    return root;
  }
};
