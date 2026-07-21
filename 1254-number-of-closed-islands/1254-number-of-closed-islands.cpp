class Solution {
    void dfs(vector<vector<int>>& grid, int r, int c){
        int n = grid.size(), m = grid[0].size();
        grid[r][c] = 1;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for(int k = 0; k < 4; ++k){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0){
                dfs(grid, nr, nc);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        for(int i = 0; i < n; ++i){
            if(grid[i][0] == 0){
                    dfs(grid, i , 0); 
            }
            if(grid[i][m-1] == 0){
                    dfs(grid, i , m-1);
            }
        }
        for(int i = 0; i < m; ++i){
            if(grid[0][i] == 0){
                    dfs(grid, 0 , i); 
            }
            if(grid[n-1][i] == 0){
                    dfs(grid, n-1 , i);
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 0){
                    dfs(grid, i , j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};