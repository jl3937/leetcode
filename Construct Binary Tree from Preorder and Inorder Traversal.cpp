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
  TreeNode *buildSubTree(vector<int> &preorder, int prepos,
                         vector<int> &inorder, int inpos, int len) {
    if (len == 0) {
      return NULL;
    }
    int val = preorder[prepos];
    for (int i = inpos; i < inpos + len; i++) {
      if (inorder[i] == val) {
        TreeNode *root = new TreeNode(val);
        root->left = buildSubTree(preorder, prepos + 1, inorder, inpos,
                                  i - inpos);
        root->right = buildSubTree(preorder, prepos + 1 + i - inpos,
                                   inorder, i + 1,
                                   len - 1 - i + inpos);
        return root;
      }
    }
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    return buildSubTree(preorder, 0, inorder, 0, preorder.size());
  }
};