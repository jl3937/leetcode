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
  int minDepth(TreeNode* root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (!root)
      return 0;
    queue<TreeNode*> q;
    q.push(root);
    int d = 1;
    int last_w = 1;
    int w = 0;
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      last_w--;
      if (!node->left && !node->right) {
        return d;
      }
      if (node->left) {
        q.push(node->left);
        w++;
      }
      if (node->right) {
        q.push(node->right);
        w++;
      }
      if (last_w == 0) {
        last_w = w;
        w = 0;
        d++;
      }
    }
  }
};
