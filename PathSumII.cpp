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
  vector<vector<int> > pathSum(TreeNode* root, int sum) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function

    vector<vector<int> > r;
    vector<vector<int> > rightPath;
    if (!root)
      return r;
    if (!root->left && !root->right) {
      if (sum == root->val) {
        vector<int> path;
        path.push_back(sum);
        r.push_back(path);
      }
      return r;
    }
    r = pathSum(root->left, sum - root->val);
    rightPath = pathSum(root->right, sum - root->val);
    r.insert(r.end(), rightPath.begin(), rightPath.end());
    for (int i = 0; i < r.size(); i++) {
      r[i].insert(r[i].begin(), root->val);
    }
    return r;
  }
};
