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
  // Value may be negative!!
  int maxPathSum(TreeNode* root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    r = INT_MIN;
    maxSum(root);
    return r;
  }

 private:
  int maxSum(TreeNode* root) {
    if (root == NULL)
      return 0;
    int leftSum = maxSum(root->left);
    int rightSum = maxSum(root->right);
    if (leftSum + rightSum + root->val > r) {
      r = leftSum + rightSum + root->val;
    }
    return max(0, max(leftSum, rightSum) + root->val);
  }
  int r;
};
