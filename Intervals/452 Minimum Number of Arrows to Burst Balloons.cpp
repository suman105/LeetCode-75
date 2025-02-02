class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    if (points.empty())
      return 0;

    // Sort the balloons based on their end position (xend)
    sort(
        points.begin(), points.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

    int arrows = 1;
    int prevEnd = points[0][1];

    for (int i = 1; i < points.size(); i++) {
      if (points[i][0] > prevEnd) {
        arrows++;
        prevEnd = points[i][1];
      }
    }

    return arrows;
  }
};