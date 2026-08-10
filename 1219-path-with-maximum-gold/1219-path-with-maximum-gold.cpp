class Solution {
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    int dfs(vector<vector<int>>& grid, int r, int c){
        int n = grid.size(), m = grid[0].size();
        if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0) return 0;
        int curr = grid[r][c];
        int localGold = curr;
        grid[r][c] = 0;
        for(int i = 0; i < 4; ++i){
            int nr = r + dr[i];
            int nc = c + dc[i];
            localGold = max(localGold, curr + dfs(grid, nr, nc));
        }
        grid[r][c] = curr;
        return localGold;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxGold = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] != 0){
                    maxGold = max(maxGold, dfs(grid, i, j));
                }
            }
        }
        return maxGold;
    }
};