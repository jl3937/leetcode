/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
 public:
  void connect(TreeLinkNode* root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (!root)
      return;
    queue<TreeLinkNode*> q;
    q.push(root);
    TreeLinkNode* prev = NULL;
    while (!q.empty()) {
      TreeLinkNode* node = q.front();
      q.pop();
      if (node->left) {
        q.push(node->left);
        if (prev)
          prev->next = node->left;
        prev = node->left;
      }
      if (node->right) {
        q.push(node->right);
        if (prev)
          prev->next = node->right;
        prev = node->right;
      }
      if (!node->next) {
        prev = NULL;
      }
    }
  }
};
