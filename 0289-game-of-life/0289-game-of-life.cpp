class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        int dr[] = {-1, -1, -1, 0, +1, +1, +1, 0};
        int dc[] = {-1, 0, +1, +1, +1, 0, -1, -1};
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int alive = 0;
                for(int k = 0; k < 8; ++k){
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                        if(board[nr][nc] == 3 || board[nr][nc] == 1) alive++;
                        if(board[i][j] == 1 && alive > 3){
                            board[i][j] = 3;
                            break; 
                        } 
                    }
                }
                if(board[i][j] == 1 && alive < 2){
                    board[i][j] = 3;
                    continue;
                }
                if(board[i][j] == 0 && alive == 3){
                    board[i][j] = 2;
                    continue;
                }
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j] == 2) board[i][j] = 1;
                if(board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
};