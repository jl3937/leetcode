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
  ListNode* swapPairs(ListNode* head) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    ListNode* cur = head;
    ListNode* prev = NULL;
    while (cur && cur->next) {
      ListNode* next = cur->next->next;
      if (prev) {
        prev->next = cur->next;
      } else {
        head = cur->next;
      }
      cur->next->next = cur;
      cur->next = next;
      prev = cur;
      cur = next;
    }
    return head;
  }
};
