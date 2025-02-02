class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int left = 0, maxLen = 0, zcount = 0;

    for (int right = 0; right < nums.size(); right++) {
      if (nums[right] == 0)
        zcount++;
      if (zcount > k) {
        if (!nums[left])
          zcount--;
        left++;
      }
      maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
  }
};