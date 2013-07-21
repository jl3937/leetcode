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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)
          return false;
        if (!root->left && !root->right) {
          return sum == root->val;
        }
        if (hasPathSum(root->left, sum - root->val)) {
          return true;
        }
        return hasPathSum(root->right, sum - root->val);
    }
};
