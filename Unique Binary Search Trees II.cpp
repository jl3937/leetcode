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
  TreeNode *cloneTree(TreeNode *root) {
    if (!root)
      return NULL;
    TreeNode *r = new TreeNode(root->val);
    r->left = cloneTree(root->left);
    r->right = cloneTree(root->right);
    return r;
  }
  void addVal(TreeNode *root, int val) {
    if (!root)
      return;
    root->val += val;
    addVal(root->left, val);
    addVal(root->right, val);
  }
  vector<TreeNode *> generateTrees(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<TreeNode *> r;
    if (n == 0) {
      r.push_back(NULL);
      return r;
    }
    for (int i = 0; i < n; i++) {
      vector<TreeNode *> left = generateTrees(i);
      vector<TreeNode *> right = generateTrees(n - i - 1);
      for (int j = 0; j < right.size(); j++)
        addVal(right[j], i + 1);
      for (int j = 0; j < left.size(); j++) {
        for (int k = 0; k < right.size(); k++) {
          TreeNode *root = new TreeNode(i + 1);
          root->left = cloneTree(left[j]);
          root->right = cloneTree(right[k]);
          r.push_back(root);
        }
      }
    }
    return r;
  }
};