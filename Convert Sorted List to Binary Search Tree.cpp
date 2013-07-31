/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
 private:
  ListNode* sortedListToBST(ListNode* head, TreeNode* root, int n) {
    int mid = n / 2;
    if (mid > 0) {
      root->left = new TreeNode(0);
      head = sortedListToBST(head, root->left, mid);
    }
    root->val = head->val;
    head = head->next;
    if (mid + 1 < n) {
      root->right = new TreeNode(0);
      head = sortedListToBST(head, root->right, n - mid - 1);
    }
    return head;
  }
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (!head)
      return NULL;
    ListNode* cur = head;
    int n = 0;
    while (cur) {
      n++;
      cur = cur->next;
    }
    TreeNode* root = new TreeNode(0);
    sortedListToBST(head, root, n);
    return root;
  }
};
