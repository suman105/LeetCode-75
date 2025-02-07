class Solution {
    public:
        int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
            int m = maze.size(), n = maze[0].size();
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            queue<pair<int, int>> q;
            q.push({entrance[0], entrance[1]});
            visited[entrance[0]][entrance[1]] = true;
            
            // Directions: up, down, left, right
            vector<int> dirs = {-1, 0, 1, 0, -1, 0};
            int steps = 0;
            
            while (!q.empty()) {
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    auto [x, y] = q.front();
                    q.pop();
                    
                    // Check if it's an exit (boundary of the maze)
                    if ((x != entrance[0] || y != entrance[1]) && (x == 0 || x == m - 1 || y == 0 || y == n - 1)) {
                        return steps;
                    }
                    
                    // Explore all four possible directions
                    for (int j = 0; j < 4; j++) {
                        int nx = x + dirs[j], ny = y + dirs[j + 1];
                        
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == '.' && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                steps++;
            }
            
            return -1;  // No exit found
        }
    };
    