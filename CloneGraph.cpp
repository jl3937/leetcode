/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    // Note: The Solution object is instantiated only once and is reused by each
    // test case.
    if (!node)
      return NULL;
    map<UndirectedGraphNode *, UndirectedGraphNode *> node_map;
    queue<UndirectedGraphNode *> q;
    q.push(node);
    node_map[node] = new UndirectedGraphNode(node->label);
    while (!q.empty()) {
      UndirectedGraphNode *node = q.front();
      q.pop();
      for (int i = 0; i < node->neighbors.size(); i++) {
        if (!node_map.count(node->neighbors[i])) {
          node_map[node->neighbors[i]] =
              new UndirectedGraphNode(node->neighbors[i]->label);
          q.push(node->neighbors[i]);
        }
      }
    }
    for (auto iter = node_map.begin(); iter != node_map.end(); iter++) {
      for (int i = 0; i < iter->first->neighbors.size(); i++) {
        iter->second->neighbors.push_back(node_map[iter->first->neighbors[i]]);
      }
    }
    return node_map[node];
  }
};
