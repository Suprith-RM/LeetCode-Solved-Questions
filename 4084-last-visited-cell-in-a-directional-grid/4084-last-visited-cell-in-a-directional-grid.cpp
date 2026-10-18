class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        pair<int, int> cord = {0, 0};
        pair<int, int> prev = {0, 0};
        while(cord.first < n && cord.first >= 0 && cord.second < m && cord.second >= 0 && grid[cord.first][cord.second] != 'X'){
            prev = cord;
            int x = cord.first;
            int y = cord.second;
            if(grid[x][y] == 'R'){
                cord.second++;
            }
            else if(grid[x][y] == 'L'){
                cord.second--;
            }
            else if(grid[x][y] == 'D'){
                cord.first++;
            }
            else if(grid[x][y] == 'U'){
                cord.first--;
            }
            grid[x][y] = 'X';
        }
        vector<int> arr = {prev.first, prev.second};
        return arr;
    }
};