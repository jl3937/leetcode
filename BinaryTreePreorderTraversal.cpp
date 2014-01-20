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
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> r;
    if (!root) {
      return r;
    }
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()) {
      TreeNode *cur = s.top();
      s.pop();
      r.push_back(cur->val);
      if (cur->right) {
        s.push(cur->right);
      }
      if (cur->left) {
        s.push(cur->left);
      }
    }
    return r;
  }
};
