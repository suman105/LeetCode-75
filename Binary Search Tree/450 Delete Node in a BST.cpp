class Solution {
public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root)
      return NULL;
    if (root->val > key)
      root->left = deleteNode(root->left, key);
    else if (root->val < key)
      root->right = deleteNode(root->right, key);
    else {
      TreeNode *temp;
      if (!root->left) {
        temp = root->right;
        delete root;
        return temp;
      } else if (!root->right) {
        temp = root->left;
        delete root;
        return temp;
      }
      temp = findMin(root->right);
      root->val = temp->val;
      root->right = deleteNode(root->right, temp->val);
    }
    return root;
  }

  TreeNode *findMin(TreeNode *root) {
    while (root && root->left)
      root = root->left;
    return root;
  }
};