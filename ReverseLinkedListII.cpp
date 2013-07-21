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
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    ListNode *cur = head;
    ListNode *prev = NULL;
    ListNode *next = NULL;
    ListNode *first = NULL;
    ListNode *second = NULL;
    n -= m;
    m--;
    while (m-- > 0) {
      prev = cur;
      first = cur;
      cur = cur->next;
    }
    prev = cur;
    second = cur;
    cur = cur->next;
    while (n-- > 0) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    second->next = cur;
    if (first)
      first->next = prev;
    else
      head = prev;
    return head;
  }
};
