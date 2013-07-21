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
  ListNode* partition(ListNode* head, int x) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    ListNode* new_head = NULL;
    ListNode* cur = head;
    ListNode* new_cur = NULL;
    ListNode* prev = NULL;
    while (cur) {
      if (cur->val >= x) {
        if (prev == NULL) {
          head = cur->next;
          if (new_head == NULL) {
            new_head = cur;
            new_cur = cur;
          } else {
            new_cur->next = cur;
            new_cur = new_cur->next;
          }
          cur = cur->next;
          new_cur->next = NULL;
        } else {
          prev->next = cur->next;
          if (new_head == NULL) {
            new_head = cur;
            new_cur = new_head;
          } else {
            new_cur->next = cur;
            new_cur = new_cur->next;
          }
          new_cur->next = NULL;
          cur = prev->next;
        }
      } else {
        prev = cur;
        cur = cur->next;
      }
    }
    if (prev) {
      prev->next = new_head;
    } else {
      head = new_head;
    }
    return head;
  }
};
