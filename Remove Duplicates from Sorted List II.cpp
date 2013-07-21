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
      bool dup = false;
      int val = cur->val;
      while (cur->next) {
        if (cur->next->val != val) {
          break;
        }
        cur = cur->next;
        dup = true;
      }
      if (dup) {
        if (prev) {
          prev->next = cur->next;
        } else {
          head =cur->next;
        }
      } else {
        prev = cur;
      }
      cur = cur->next;
    }
    return head;
  }
};