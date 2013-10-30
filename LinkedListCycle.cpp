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
  bool hasCycle(ListNode *head) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    set<ListNode *> node_set;
    while (head) {
      if (node_set.count(head)) {
        return true;
      }
      node_set.insert(head);
      head = head->next;
    }
    return false;
  }
};
