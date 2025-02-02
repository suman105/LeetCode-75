class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    int totalSum = 0, leftSum = 0, rightSum = 0, n = nums.size();

    for (int num : nums)
      totalSum += num;

    for (int i = 0; i < n; i++) {
      rightSum = totalSum - leftSum - nums[i];

      if (leftSum == rightSum)
        return i;

      leftSum += nums[i];
    }

    return -1;
  }
};