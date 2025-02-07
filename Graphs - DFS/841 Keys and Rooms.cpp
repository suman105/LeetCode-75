class Solution {
    public:
        void dfs(int room, std::vector<std::vector<int>>& rooms, std::unordered_set<int>& visited) {
            visited.insert(room);
            for (int key : rooms[room]) {
                if (visited.find(key) == visited.end()) {
                    dfs(key, rooms, visited);
                }
            }
        }
        
        bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
            std::unordered_set<int> visited;
            dfs(0, rooms, visited);
            return visited.size() == rooms.size();
        }
    };
    