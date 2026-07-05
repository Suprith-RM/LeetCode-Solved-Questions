class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 2){
                    q.push({ 0, { i, j }});
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            int t = q.front().first; 
            auto [r, c] = q.front().second;
            time = max(time, t); 
            q.pop();
            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, 1, -1};
            for(int k = 0; k < 4; ++k){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr < n && nr >= 0 && nc < m && nc >= 0 && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;
                    q.push({t+1, {nr, nc}});
                }
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};