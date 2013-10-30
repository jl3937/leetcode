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
  int heightIfBalanced(TreeNode *root) {
    if (!root)
      return 0;
    int left = heightIfBalanced(root->left);
    if (left == -1)
      return -1;
    int right = heightIfBalanced(root->right);
    if (right == -1)
      return -1;
    if (abs(left - right) > 1) {
      return -1;
    }
    return max(left, right) + 1;
  }
  
public:
  bool isBalanced(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    return heightIfBalanced(root) != -1;
  }
};
