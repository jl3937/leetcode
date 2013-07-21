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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (!l1)
      return l2;
    if (!l2)
      return l1;
    ListNode* head, *first, *second;
    if (l1->val < l2->val) {
      head = l1;
      first = l1;
      second = l2;
    } else {
      head = l2;
      first = l2;
      second = l1;
    }
    ListNode* prev = NULL;
    while (second) {
      int val = second->val;
      while (first && first->val <= val) {
        prev = first;
        first = first->next;
      }
      prev->next = second;
      second = second->next;
      prev->next->next = first;
      prev = prev->next;
    }
    return head;
  }
};
