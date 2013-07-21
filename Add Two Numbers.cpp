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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    ListNode *l3, *r;
    int first = true;
    int carry = 0;
    while (l1 != NULL || l2 != NULL) {
      int sum = carry;
      if (l1 != NULL) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2 != NULL) {
        sum += l2->val;
        l2 = l2->next;
      }
      if (sum >= 10) {
        sum -= 10;
        carry = 1;
      } else {
        carry = 0;
      }
      if (first) {
        l3 = new ListNode(sum);
        r = l3;
        first = false;
      } else {
        l3->next = new ListNode(sum);
        l3 = l3->next;
      }
    }
    if (carry) {
      l3->next = new ListNode(carry);
    }
    return r;
  }
};