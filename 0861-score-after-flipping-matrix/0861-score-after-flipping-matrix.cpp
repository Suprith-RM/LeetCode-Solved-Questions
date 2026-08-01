class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; ++i){
            if(grid[i][0] == 0){
                for(int j = 0; j < m; ++j){
                    grid[i][j] ^= 1;
                }
                
            }
        }
        for(int i = 1; i < m; ++i){
            int zeros = 0;
            for(int j = 0; j < n; ++j){
                if(grid[j][i] == 0) zeros++;
            }
            if(zeros * 2 > n){
                for(int j = 0; j < n; ++j){
                   grid[j][i] ^= 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int fct = 1;
            for(int j = m-1; j >= 0; --j){
                ans += (fct * grid[i][j]);
                fct *= 2;
            }
        }
        return ans;
    }
};