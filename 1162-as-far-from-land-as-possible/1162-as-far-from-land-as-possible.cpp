class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,pair<int, int>>> q;
        bool water = false, land = false;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    land = true;
                    q.push({0, {i, j}});
                } else{
                    water = true;
                }
            }
        }
        if(!water || !land) return -1;
        int max_dist = 0, dr[] = {1, -1, 0, 0}, dc[] = {0, 0 , 1, -1};
        while(!q.empty()){
            int dist = q.front().first;
            auto [r, c] = q.front().second;
            q.pop();
            max_dist = max(max_dist, dist);
            for(int k = 0; k < 4; ++k){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr < n && nr >= 0 && nc < n && nc >= 0 && grid[nr][nc] == 0){
                    grid[nr][nc] = 1;
                    q.push({dist+1, {nr, nc}});
                }
            }
        }
        return max_dist;
    }
};