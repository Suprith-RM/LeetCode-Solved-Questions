class Solution {
    void multi_bfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, queue<pair<int, int>>& q){
        int n = heights.size();
        int m = heights[0].size();
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            vis[r][c] = true;
            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0 , 1, -1};
            for(int k = 0; k < 4; ++k){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr < n && nr >= 0 && nc < m && nc >= 0 && !vis[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    q.push({nr , nc});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        queue<pair<int, int>> pacific_q;
        queue<pair<int, int>> atlantic_q;
        for (int j = 0; j < m; j++) {
            pacific_q.push({0, j});    
            atlantic_q.push({n - 1, j}); 
        }
        for (int i = 0; i < n; i++) {
            pacific_q.push({i, 0});      
            atlantic_q.push({i, m - 1}); 
        }
        multi_bfs(heights, pacific, pacific_q);
        multi_bfs(heights, atlantic, atlantic_q);
        vector<vector<int>> ans;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
}; 

