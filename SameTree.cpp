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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (!p && !q)
      return true;
    if (!p || !q)
      return false;
    if (p->val != q->val)
      return false;
    if (!isSameTree(p->left, q->left))
      return false;
    if (!isSameTree(p->right, q->right))
      return false;
    return true;
  }
};
