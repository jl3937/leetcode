/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = NULL;
    ListNode *cur = head;
    ListNode *next = NULL;
    while (cur) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return prev;
  }

public:
  void reorderList(ListNode *head) {
    if (head == NULL) {
      return;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    while (true) {
      fast = fast->next;
      if (fast == NULL) {
        break;
      }
      fast = fast->next;
      if (fast == NULL) {
        break;
      }
      slow = slow->next;
    }
    ListNode *mid = slow->next;
    slow->next = NULL;
    mid = reverseList(mid);
    ListNode *next, *midNext;
    while (true) {
      if (!head)
        break;
      next = head->next;
      head->next = mid;
      if (!mid)
        break;
      midNext = mid->next;
      mid->next = next;
      head = next;
      mid = midNext;
    }
  }
};
