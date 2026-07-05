class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        q.push({ sr, sc });
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vis[sr][sc] = true;
        int clr = image[sr][sc];
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            if(image[r][c] == clr) image[r][c] = color;
            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, 1, -1};
            for(int k = 0; k < 4; ++k){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m  && image[nr][nc] == clr && !vis[nr][nc]){
                    vis[nr][nc] = true;
                    q.push({ nr, nc });
                }
            }
        }
        return image;
    }
};