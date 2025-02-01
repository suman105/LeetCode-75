class Solution {
public:
  int maxLength = 0;

  void dfs(TreeNode *node, bool isLeft, int length) {
    if (!node)
      return;

    maxLength = max(maxLength, length);

    if (isLeft) {
      dfs(node->left, false, length + 1);
      dfs(node->right, true, 1);
    } else {
      dfs(node->right, true, length + 1);
      dfs(node->left, false, 1);
    }
  }

  int longestZigZag(TreeNode *root) {
    if (!root)
      return 0;
    dfs(root->left, false, 1);
    dfs(root->right, true, 1);
    return maxLength;
  }
};