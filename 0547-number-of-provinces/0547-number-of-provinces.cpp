class Solution {
    void dfs(int node, vector<vector<int>>& matrix, vector<bool>& vis){
        int n = matrix.size();
        for(int i = 0; i < n; ++i){
            if(!vis[i] && matrix[node][i] == 1){
                vis[i] = true;
                dfs(i, matrix, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& matrix) {
        int n = matrix.size(), cnt = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; ++i){
            if(!vis[i] && matrix[i][i] == 1){
                vis[i] = true;
                cnt++;
                dfs(i, matrix, vis);
            }
        }
        return cnt;
    }
};