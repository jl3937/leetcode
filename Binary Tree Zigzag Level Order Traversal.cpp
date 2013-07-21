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
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > r;
    stack<TreeNode *> s[2];
    if (root)
      s[0].push(root);
    vector<int> level;
    bool cur = 0;
    while (!s[cur].empty()) {
      while (!s[cur].empty()) {
        TreeNode *node = s[cur].top();
        s[cur].pop();
        level.push_back(node->val);
        if (!cur) {
          if (node->left)
            s[!cur].push(node->left);
          if (node->right)
            s[!cur].push(node->right);
        } else {
          if (node->right)
            s[!cur].push(node->right);
          if (node->left)
            s[!cur].push(node->left);
        }
      }
      r.push_back(level);
      level.clear();
      cur = !cur;
    }
    return r;
  }
};