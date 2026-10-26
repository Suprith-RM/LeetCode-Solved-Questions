class Solution {
    void dfs(vector<vector<int>>& grid, int r, int c, long long& sum) {
        sum += grid[r][c];
        grid[r][c] = -1;
        int n = grid.size(), m = grid[0].size();
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] > 0) {
                dfs(grid, nr, nc, sum);
            }
        }
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] > 0) {
                    long long sum = 0;
                    dfs(grid, i, j, sum);
                    if (sum % k == 0)
                        ans++;
                }
            }
        }
        return ans;
    }
};