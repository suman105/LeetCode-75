class Solution {
public:
  int maxLevelSum(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    int level = 1, res = 1, maxsum = root->val;
    while (!q.empty()) {
      int sum = 0;
      int n = q.size();
      while (n--) {
        TreeNode *temp = q.front();
        q.pop();
        if (temp) {
          sum += temp->val;
          if (temp->left)
            q.push(temp->left);
          if (temp->right)
            q.push(temp->right);
        }
      }
      if (maxsum < sum) {
        maxsum = sum;
        res = level;
      }
      ++level;
    }
    return res;
  }
};