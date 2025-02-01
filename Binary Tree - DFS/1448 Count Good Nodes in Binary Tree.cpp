class Solution {
public:
  void countNodes(TreeNode *root, int &cnt, int max) {
    if (!root)
      return;
    if (root->val >= max) {
      cnt++;
      max = root->val;
    }

    countNodes(root->left, cnt, max);
    countNodes(root->right, cnt, max);
  }

  int goodNodes(TreeNode *root) {
    int cnt = 1;

    countNodes(root->left, cnt, root->val);
    countNodes(root->right, cnt, root->val);

    return cnt;
  }
};