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
  vector<int> inorderTraversal(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> r;
    if (!root)
      return r;
    stack<TreeNode *> s;
    TreeNode *node = root;
    while (root) {
      s.push(root);
      root = root->left;
    }
    while (!s.empty()) {
      TreeNode* node = s.top();
      s.pop();
      r.push_back(node->val);
      node = node->right;
      while (node) {
        s.push(node);
        node = node->left;
      }
    }
    return r;
  }
};
