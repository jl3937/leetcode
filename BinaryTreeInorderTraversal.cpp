/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> r;
    if (!root)
      return r;
    stack<pair<TreeNode *, int> > s;
    s.push(make_pair(root, 0));
    while (!s.empty()) {
      int state = s.top().second;
      TreeNode* node = s.top().first;
      switch (state) {
        case 0:
          s.top().second++;
          if (node->left)
            s.push(make_pair(node->left, 0));
          break;
        case 1:
          r.push_back(node->val);
          s.top().second++;
          if (node->right)
            s.push(make_pair(node->right, 0));
          break;
        case 2:
          s.pop();
      }
    }
    return r;
  }
};
