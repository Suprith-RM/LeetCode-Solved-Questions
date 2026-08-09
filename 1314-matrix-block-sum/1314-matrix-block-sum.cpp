class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i = 0; i < n; ++i){
            for(int j = 1; j < m; ++j){
                mat[i][j] = mat[i][j] + mat[i][j-1];
            }
        }
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < m; ++j){
                mat[i][j] = mat[i][j] + mat[i-1][j];
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                pair<int, int> b_r = {min(i + k, n-1), min(j + k, m-1)};
                pair<int, int> b_l = {min(i + k, n-1), max(j - k, 0)};
                pair<int, int> t_r = {max(i - k, 0), min(j + k, m-1)};
                pair<int, int> t_l = {max(i - k, 0), max(j - k, 0)};
                ans[i][j] = mat[b_r.first][b_r.second];
                if(b_l.second > 0) ans[i][j] -= mat[b_l.first][b_l.second - 1];
                if(t_r.first > 0) ans[i][j] -= mat[t_r.first - 1][t_r.second];
                if(b_l.second > 0 && t_r.first > 0) ans[i][j] += mat[t_l.first-1][t_l.second-1];
            }
        }
        return ans;
    }
};