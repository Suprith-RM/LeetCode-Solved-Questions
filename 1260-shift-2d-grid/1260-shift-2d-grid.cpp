class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<int> shift(m * n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                shift[(i * m) + j] = grid[i][j];
        int rotate_times = k % (m * n);
        reverse(shift.begin(), shift.end());
        reverse(shift.begin(), shift.begin() + rotate_times);
        reverse(shift.begin() + rotate_times, shift.end());
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                grid[i][j] = shift[(i * m) + j];   
        return grid;
    }
};