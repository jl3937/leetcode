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
    TreeLinkNode *head = root;
    while (head) {
      TreeLinkNode *node = head;
      head = NULL;
      TreeLinkNode *prev = NULL;
      while (node) {
        if (node->left) {
          if (prev) {
            prev->next = node->left;
          } else {
            head = node->left;
          }
          prev = node->left;
        }
        if (node->right) {
          if (prev) {
            prev->next = node->right;
          } else {
            head = node->right;
          }
          prev = node->right;
        }
        node = node->next;
      }
    }
  }
};
