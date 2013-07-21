/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class my_cmp {
 public:
  bool operator()(const ListNode* l, ListNode* r) { return l->val > r->val; }
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (lists.empty())
      return NULL;
    typedef priority_queue<ListNode*, vector<ListNode*>, my_cmp> mypq_type;
    mypq_type q;
    for (int i = 0; i < lists.size(); i++) {
      if (lists[i])
        q.push(lists[i]);
    }
    ListNode* head = NULL;
    ListNode* cur = NULL;
    while (!q.empty()) {
      ListNode* node = q.top();
      q.pop();
      if (node->next)
        q.push(node->next);
      if (cur) {
        cur->next = node;
        cur = cur->next;
      } else {
        head = node;
        cur = head;
      }
      cur->next = NULL;
    }
    return head;
  }
};
