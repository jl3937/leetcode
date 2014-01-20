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
  ListNode *detectCycle(ListNode *head) {
    if (!head) {
      return NULL;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    do {
      for (int i = 0; i < 2; i++) {
        fast = fast->next;
        if (!fast) {
          return NULL;
        }
      }
      slow = slow->next;
    } while (fast != slow);
    slow = head;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return fast;
  }
};
