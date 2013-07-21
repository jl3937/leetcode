/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    ListNode *cur = head;
    ListNode *prev = NULL;
    while (cur) {
      if (prev && prev->val == cur->val) {
        prev->next = cur->next;
        cur = cur->next;
      } else {
        prev = cur;
        cur = cur->next;
      }
    }
    return head;
  }
};