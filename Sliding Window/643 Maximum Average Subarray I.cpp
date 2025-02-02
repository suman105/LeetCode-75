class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    int n = nums.size();
    int current = 0, curMax = INT_MIN;

    for (int i = 0; i < n; i++) {
      if (i - k >= 0)
        current -= nums[i - k];

      current += nums[i];
      curMax = max(curMax, current);
    }

    return double(curMax) / k;
  }
};