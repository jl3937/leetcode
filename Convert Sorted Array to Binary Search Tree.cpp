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
  TreeNode *sortedArrayToBST(vector<int> &num, int pos, int len) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (len == 0)
      return NULL;
    int mid = pos + len / 2;
    TreeNode *node = new TreeNode(num[mid]);
    node->left = sortedArrayToBST(num, pos, mid - pos);
    node->right = sortedArrayToBST(num, mid + 1, pos + len - mid - 1);
    return node;
  }
public:
  TreeNode *sortedArrayToBST(vector<int> &num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    return sortedArrayToBST(num, 0, num.size());
  }
};