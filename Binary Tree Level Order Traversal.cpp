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
  vector<vector<int> > levelOrder(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > r;
    if (!root)
      return r;
    queue<TreeNode *> q;
    vector<int> level;
    q.push(root);
    int last_n = 1;
    int cur_n = 0;
    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();
      last_n--;
      level.push_back(node->val);

      if (node->left) {
        q.push(node->left);
        cur_n++;
      }
      if (node->right) {
        q.push(node->right);
        cur_n++;
      }
      if (last_n == 0) {
        last_n = cur_n;
        cur_n = 0;
        r.push_back(level);
        level.clear();
      }
    }
    return r;
  }
};