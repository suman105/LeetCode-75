class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int maxlen = 0, zcount = 0, left = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (!nums[i])
        zcount++;

      if (zcount > 1) {
        if (!nums[left])
          zcount--;
        left++;
      }

      maxlen = max(maxlen, i - left);
    }

    return maxlen;
  }
};