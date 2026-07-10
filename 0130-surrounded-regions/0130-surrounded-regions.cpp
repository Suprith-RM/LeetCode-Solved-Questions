class Solution {
    void dfs(vector<vector<char>>& board, int r, int c, vector<vector<bool>> &vis, queue<pair<int, int>>& q, bool& enclosed){
        int n = board.size();
        int m = board[0].size();
        vis[r][c] = true;
        if(r == n-1 || c == m-1 || r == 0 || c == 0){
            enclosed = false;
        } 
        q.push({r, c});
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        for(int k = 0; k < 4; ++k){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr < n && nr >= 0 && nc < m && nc >= 0 && board[nr][nc] == 'O' && !vis[nr][nc]){
                dfs(board, nr, nc, vis, q, enclosed);
            }
        }
    }
    void set(vector<vector<char>>& board, queue<pair<int, int>> &q){
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            board[r][c] = 'X';
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j] == 'O' && !vis[i][j]){
                    queue<pair<int, int>> q;
                    bool enclosed = true;
                    (dfs(board, i, j, vis, q, enclosed)); 
                    if(enclosed) set(board, q);
                }
            }
        }
    }
};