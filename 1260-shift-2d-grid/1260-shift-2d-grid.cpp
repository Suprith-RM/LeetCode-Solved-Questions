class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < k; ++i){
            int temp = grid[n-1][m-1];
            for(int j = n-1; j > 0; --j){
                grid[j][m-1] = grid[j-1][m-1];
            }
            grid[0][m-1] = temp;
            for(int j = 0; j < n; ++j){
                int temp = grid[j][m-1];
                for(int k = m-1; k > 0 ; --k){
                    grid[j][k] = grid[j][k-1];
                }
                grid[j][0] = temp;
            }
        }
        return grid;
    }
};