class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<int> vert(n, 0);
        vector<int> horz(m, 0);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1){
                    vert[i]++;
                    horz[j]++;
                    cnt++;
                }
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1 && vert[i] == 1 && horz[j] == 1){
                    cnt--;
                }
            }
        }
        return cnt;
    }
};