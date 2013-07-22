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
  int sum;
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sum = 0;
        if (!root)
          return 0;
        visitNode(root, 0);
        return sum;
    }
    void visitNode(TreeNode *root, int parent) {
      int cur = parent * 10 + root->val;
      if (!root->left && !root->right) {
        sum += cur;
      } else {
        if (root->left) {
          visitNode(root->left, cur);
        }
        if (root->right) {
          visitNode(root->right, cur);
        }
      }
    }
};
