class Solution {
    vector<int> store(vector<vector<int>>& grid, int l, int r, int u, int d){
        vector<int> res;
        for(int i = u; i <= d; ++i){
            res.push_back(grid[i][l]);
        }
        for(int i = l + 1; i <= r; ++i){
            res.push_back(grid[d][i]);
        }
        for(int i = d-1; i >= u; --i){
            res.push_back(grid[i][r]);
        }
        for(int i = r - 1; i > l; --i){
            res.push_back(grid[u][i]);
        }
        return res;
    }
    void assign(vector<vector<int>>& grid, int l, int r, int u, int d, vector<int>& arr, int k){
        int n = arr.size();
        int idx = (n - k) % n;
        for(int i = u; i <= d; ++i){
            grid[i][l] = arr[idx];
            idx = (idx + 1) % n;
        }
        for(int i = l + 1; i <= r; ++i){
            grid[d][i] = arr[idx];
            idx = (idx + 1) % n;

        }
        for(int i = d-1; i >= u; --i){
            grid[i][r] = arr[idx];
            idx = (idx + 1) % n;

        }
        for(int i = r - 1; i > l; --i){
            grid[u][i] = arr[idx];
            idx = (idx + 1) % n;
        }
    }
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int left = 0, right = m-1, up = 0, down = n-1;
        while(left < right && up < down){
            vector<int> arr = store(grid, left, right, up, down);
            int turn = k % arr.size();
            assign(grid, left, right, up, down, arr, turn);
            left++, right--, up++, down--;
        }
        return grid;
    }
};