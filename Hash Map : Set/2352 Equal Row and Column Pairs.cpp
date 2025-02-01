class Solution {
public:
  int equalPairs(vector<vector<int>> &grid) {
    int n = grid.size();
    unordered_map<string, int> m;

    for (int i = 0; i < n; i++) {
      string row = "";
      for (int j = 0; j < n; j++) {
        row += to_string(grid[i][j]) + ",";
      }
      m[row]++;
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
      string col = "";
      for (int j = 0; j < n; j++) {
        col += to_string(grid[j][i]) + ",";
      }

      result += m[col];
    }

    return result;
  }
};