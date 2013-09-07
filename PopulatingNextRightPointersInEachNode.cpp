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
  void connect(TreeLinkNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (root == NULL)
      return;
    TreeLinkNode *head = root;
    while (head->left) {
      TreeLinkNode *node = head;
      head = head->left;
      while (true) {
        node->left->next = node->right;
        if (node->next) {
          node->right->next = node->next->left;
          node = node->next;
        } else {
          node->right->next = NULL;
          break;
        }
      }
    }
  }
};
