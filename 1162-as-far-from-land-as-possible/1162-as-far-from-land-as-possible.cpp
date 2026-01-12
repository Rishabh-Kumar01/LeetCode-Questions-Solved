class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) q.push({i, j});
            }
        }

        if(q.empty() || q.size() == m * n) return -1;

         int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        int maxDist = 0;
        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            // Explore all 4 neighbors
            for(int i = 0; i < 4; i++) {
                int newRow = row + dx[i];
                int newCol = col + dy[i];
                
                // Check bounds and if it's water (unvisited)
                if(newRow >= 0 && newRow < n && 
                   newCol >= 0 && newCol < n &&
                   grid[newRow][newCol] == 0) {
                    
                    // Update distance (from land, grid[row][col] already has distance)
                    grid[newRow][newCol] = grid[row][col] + 1;
                    maxDist = grid[newRow][newCol];  // Track maximum
                    q.push({newRow, newCol});
                }
            }
        }
        
        return maxDist - 1;
    }
};