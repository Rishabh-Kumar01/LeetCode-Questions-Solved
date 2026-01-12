class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty() || rooms[0].empty()) return;
        
        int m = rooms.size();
        int n = rooms[0].size();
        queue<pair<int, int>> q;
        
        // Add all gates to queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        // Direction vectors: right, down, left, up
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        // BFS from all gates simultaneously
        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            // Explore all 4 neighbors
            for(int dir = 0; dir < 4; dir++) {
                int newRow = row + dx[dir];
                int newCol = col + dy[dir];
                
                // Check bounds and if it's an unvisited empty room
                if(newRow >= 0 && newRow < m && 
                   newCol >= 0 && newCol < n &&
                   rooms[newRow][newCol] == INT_MAX) {
                    
                    rooms[newRow][newCol] = rooms[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
};