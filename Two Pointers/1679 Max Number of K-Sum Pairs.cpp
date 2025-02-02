class Solution {
public:
  int maxOperations(vector<int> &nums, int k) {
    int cnt = 0;

    unordered_map<int, int> m;

    for (int num : nums) {
      int required = k - num;

      if (m[required] > 0) {
        cnt++;
        m[required]--;
      } else
        m[num]++;
    }

    return cnt;
  }
};