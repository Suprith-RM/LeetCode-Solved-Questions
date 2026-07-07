class Solution{
    bool isSafe(vector<vector<char>>& board, int r, int c, int i){
        char chk = i + '0';
        for(int i = 0; i < 9; i++){
            if(board[r][i] == chk) return false;
            if(board[i][c] == chk) return false;
        }
        int r_f = r/3;
        int c_f = c/3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[r_f*3 + i][c_f*3 + j] == chk){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    int temp = board[i][j] - '0';
                    board[i][j] = '.';
                    if(!isSafe(board, i, j, temp)) return false;
                    board[i][j] = temp + '0';
                }
            }
        }
        return true;
    }
};