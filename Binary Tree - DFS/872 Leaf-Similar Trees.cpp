class Solution {
public:
  void findLeaf(TreeNode *root, vector<int> &result) {
    if (!root)
      return;
    if (!root->left && !root->right) {
      result.push_back(root->val);
      return;
    }
    findLeaf(root->left, result);
    findLeaf(root->right, result);
  }

  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> first, second;
    findLeaf(root1, first);
    findLeaf(root2, second);

    return first == second;
  }
};