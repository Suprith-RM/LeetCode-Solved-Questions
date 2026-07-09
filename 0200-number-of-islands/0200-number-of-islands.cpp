class Solution {
    void dfs(vector<vector<char>>& grid, int r, int c){
        int n = grid.size(), m = grid[0].size();
        grid[r][c] = '0';
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        for(int k = 0; k < 4; ++k){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr < n && nr >= 0 && nc < m && nc >= 0 && grid[nr][nc] == '1'){
                dfs(grid, nr, nc);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};