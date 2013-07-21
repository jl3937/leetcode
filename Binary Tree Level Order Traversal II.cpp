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
  vector<vector<int> > levelOrderBottom(vector<TreeNode *> level) {
    vector<TreeNode *> next_level;
    vector<int> vals;
    for (int i = 0; i < level.size(); i++) {
      vals.push_back(level[i]->val);
      if (level[i]->left) {
        next_level.push_back(level[i]->left);
      }
      if (level[i]->right) {
        next_level.push_back(level[i]->right);
      }
    }
    vector<vector<int> > r;
    if (!next_level.empty()) {
      r = levelOrderBottom(next_level);
    }
    r.push_back(vals);
    return r;
  }
public:
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > r;
    if (!root)
      return r;
    vector<TreeNode *> level;
    level.push_back(root);
    return levelOrderBottom(level);
  }
};