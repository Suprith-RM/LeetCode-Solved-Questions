class Solution {
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int r, int c, int m, int n){
        vis[r][c] = true;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        for(int k = 0; k < 4; ++k){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1){
                dfs(grid, vis, nr, nc, m, n);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i){
             if(grid[i][0] == 1 && !vis[i][0])
                dfs(grid, vis, i, 0, m, n);

            if(grid[i][m-1] == 1 && !vis[i][m-1])
                dfs(grid, vis, i, m-1, m, n);
        }
        for(int j = 0; j < m; ++j){
            if(grid[0][j] == 1 && !vis[0][j])
                dfs(grid, vis, 0, j, m, n);

            if(grid[n-1][j] == 1 && !vis[n-1][j])
                dfs(grid, vis, n-1, j, m, n);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!vis[i][j] && grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};