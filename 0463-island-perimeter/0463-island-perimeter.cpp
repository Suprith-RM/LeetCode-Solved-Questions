class Solution {
    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& vis, int& peri){
        int n = grid.size();
        int m = grid[0].size();
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        for(int k = 0; k < 4; ++k){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                if(!vis[nr][nc]){
                    vis[nr][nc] = true;
                    dfs(grid, nr, nc, vis, peri);
                }
            } else{
                peri++;
            }
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1 && !vis[i][j]){
                    vis[i][j] = true;
                    dfs(grid, i, j, vis, perimeter);
                }
            }
        }
        return perimeter;
    }
};