class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int highest = 0, n = gain.size();
    for (int i = 1; i < n; i++) {
      gain[i] = gain[i - 1] + gain[i];
    }

    for (int num : gain)
      highest = max(highest, num);

    return highest;
  }
};