class Solution {
public:
    vector<vector<int>> highestRankedKItems(
        // Lenttttthhhhhhyyyyyyyy ASF
        vector<vector<int>>& grid,
        vector<int>& pricing,
        vector<int>& start,
        int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<tuple<int,int,int>> q;
        priority_queue<
            tuple<int,int,int,int>,
            vector<tuple<int,int,int,int>>,
            greater<tuple<int,int,int,int>>
        > pq;

        q.push({start[0], start[1], 0});
        vis[start[0]][start[1]] = true;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        while (!q.empty()) {
            auto [x, y, dist] = q.front();
            q.pop();
            if (grid[x][y] >= pricing[0] &&
                grid[x][y] <= pricing[1]) {
                pq.push({dist, grid[x][y], x, y});
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < m &&
                    ny >= 0 && ny < n &&
                    !vis[nx][ny] &&
                    grid[nx][ny] != 0) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, dist + 1});
                }
            }
        }
        vector<vector<int>> ans;
        while (k-- && !pq.empty()) {
            auto [dist, price, x, y] = pq.top();
            pq.pop();

            ans.push_back({x, y});
        }
        return ans;
    }
};