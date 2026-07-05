class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, pair<int, int>>> q;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 0){
                    vis[i][j] = true;
                    q.push({0, {i, j}});
                }
                if(grid[i][j] == 1){
                    grid[i][j] = -1;
                }
            }
        }
        while(!q.empty()){
            int dist = q.front().first;
            auto [r, c] = q.front().second;
            q.pop();
            vis[r][c] = true;
            if(grid[r][c] == -1){
                grid[r][c] = dist;
            } 
            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, 1, -1};
            for(int k = 0; k < 4; ++k){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr < n && nr >= 0 && nc < m && nc >= 0 && !vis[nr][nc]){
                    vis[nr][nc] = true;
                    q.push({dist + 1, {nr, nc}});
                }
            }
        }
        return grid;
    }
};