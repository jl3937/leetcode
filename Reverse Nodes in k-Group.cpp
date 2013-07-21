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
  ListNode *reverseKGroup(ListNode *head, int k) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    
    ListNode *current = head;
    ListNode *prevTail = NULL;
    ListNode *newHead = NULL;
    while (true) {
      bool done = false;
      ListNode *p = current;
      for (int i = 0; i < k; i++) {
        if (p == NULL) {
          done = true;
          break;
        }
        p = p->next;
      }
      if (done) {
        if (prevTail) {
          prevTail->next = current;
        } else
          newHead = current;
        break;
      }
      
      ListNode *currentTail = current;
      ListNode *prev = NULL;
      for (int i = 0; i < k; i++) {
        ListNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
      }
      if (newHead == NULL)
        newHead = prev;
      if (prevTail) {
        prevTail->next = prev;
      }
      prevTail = currentTail;
    }
    return newHead;
  }
};
