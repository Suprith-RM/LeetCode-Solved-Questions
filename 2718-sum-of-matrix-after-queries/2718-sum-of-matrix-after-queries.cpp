class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        int len = queries.size();
        long long res = 0;
        vector<bool> vis_row(n, false);
        vector<bool> vis_col(n, false);
        int rem_row = n;
        int rem_col = n;
        for(int i = len-1; i >= 0; --i){
            if(queries[i][0] == 1 && !vis_col[queries[i][1]]){
                int col = queries[i][1];
                int val = queries[i][2];
                res += val * rem_row;
                vis_col[col] = true;
                rem_col--;
            }
            else if(queries[i][0] == 0 && !vis_row[queries[i][1]]){
                int row = queries[i][1];
                int val = queries[i][2];
                res += val * rem_col;
                vis_row[row] = true;
                rem_row--;
            }
        }
        return res;
    }
};