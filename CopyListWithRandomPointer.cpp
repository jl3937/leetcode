/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    // Note: The Solution object is instantiated only once and is reused by each
    // test case.
    map<RandomListNode *, RandomListNode *> list_map;
    list_map[NULL] = NULL;
    RandomListNode *node = head;
    while (node) {
      list_map[node] = new RandomListNode(node->label);
      node = node->next;
    }
    node = head;
    while (node) {
      list_map[node]->next = list_map[node->next];
      list_map[node]->random = list_map[node->random];
      node = node->next;
    }
    return list_map[head];
  }
};
