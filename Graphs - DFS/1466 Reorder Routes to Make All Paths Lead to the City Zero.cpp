class Solution {
    public:
        int minReorder(int n, vector<vector<int>>& connections) {
            // Step 1: Build the graph
            unordered_map<int, vector<pair<int, bool>>> graph;
            
            for (auto& connection : connections) {
                int u = connection[0], v = connection[1];
                graph[u].push_back({v, true});  // true means road u -> v
                graph[v].push_back({u, false}); // false means road v -> u
            }
            
            // Step 2: Perform DFS to count reorders
            vector<bool> visited(n, false);
            int reorderCount = 0;
            
            dfs(0, graph, visited, reorderCount);
            
            return reorderCount;
        }
        
    private:
        void dfs(int node, unordered_map<int, vector<pair<int, bool>>>& graph, vector<bool>& visited, int& reorderCount) {
            visited[node] = true;
            
            for (auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                bool needsReorder = neighbor.second;
                
                if (!visited[nextNode]) {
                    // If the road needs reordering, increment reorderCount
                    if (needsReorder) {
                        reorderCount++;
                    }
                    
                    // Continue DFS traversal
                    dfs(nextNode, graph, visited, reorderCount);
                }
            }
        }
    };