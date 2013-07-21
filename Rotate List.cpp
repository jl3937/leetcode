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
  ListNode *rotateRight(ListNode *head, int k) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (!head)
      return NULL;
    int n = 1;
    ListNode *cur = head;
    while (cur->next) {
      cur = cur->next;
      n++;
    }
    cur->next = head;
    k = k % n;
    k = n - k - 1;
    cur = head;
    while (k > 0) {
      cur = cur->next;
      k--;
    }
    head = cur->next;
    cur->next = NULL;
    return head;
  }
};