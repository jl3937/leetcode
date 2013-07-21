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
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int n = 0;
    ListNode* cur = head;
    while(cur) {
      n++;
      cur = cur->next;
    }
    return sortedListToBST(&head, 0, n - 1);
  }

 private:
  TreeNode* sortedListToBST(ListNode** head, int start, int end) {
    if (start > end)
      return NULL;
    int mid = (start + end) / 2;
    TreeNode* left = sortedListToBST(head, start, mid - 1);
    TreeNode* parent = new TreeNode((*head)->val);
    // value of *head needs to be passed out.
    *head = (*head)->next;
    TreeNode* right = sortedListToBST(head, mid + 1, end);
    parent->left = left;
    parent->right = right;
    return parent;
  }
};
