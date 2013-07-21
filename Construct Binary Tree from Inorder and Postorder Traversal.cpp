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
  TreeNode *buildSubTree(vector<int> &inorder, int inpos,
                         vector<int> &postorder, int postpos, int len) {
    if (len == 0) {
      return NULL;
    }
    int val = postorder[postpos + len - 1];
    for (int i = inpos; i < inpos + len; i++) {
      if (inorder[i] == val) {
        TreeNode *root = new TreeNode(val);
        root->left = buildSubTree(inorder, inpos, postorder, postpos,
                                  i - inpos);
        root->right = buildSubTree(inorder, i + 1,
                                   postorder, postpos + i - inpos,
                                   len - 1 - i + inpos);
        return root;
      }
    }
  }
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    return buildSubTree(inorder, 0, postorder, 0, inorder.size());
  }
};