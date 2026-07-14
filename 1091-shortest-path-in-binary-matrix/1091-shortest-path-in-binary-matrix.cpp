class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        vis[0][0] = true;
        while(!q.empty()){
            int dist = q.front().first;
            auto [r, c] = q.front().second;
            q.pop();
            if(r == n-1 && c == n-1) return dist;
            int dr[] = {1, 1, 1, 0, -1, -1, -1, 0};
            int dc[] = {1, 0, -1, -1, -1, 0, 1, 1};
            for(int k = 0; k < 8; ++k){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr < n && nr >= 0 && nc < n && nc >= 0 && !vis[nr][nc] && grid[nr][nc] == 0){
                    vis[nr][nc] = true;
                    q.push({dist+1, {nr, nc}});
                }
            }
        }
        return -1;
    }
};