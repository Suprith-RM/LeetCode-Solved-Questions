class Solution {
    void dfs(int n, vector<bool>& used, int& ans, int pos){
        if(pos > n){
            ans++;
            return;
        }
        for(int i = 1; i <= n; ++i){
            if(used[i]) continue;
            if(pos % i == 0 || i % pos == 0){
                used[i] = true;
                dfs(n, used, ans, pos+1);
                used[i] = false;
            }
        }
    }
public:
    int countArrangement(int n) {
        vector<bool> used(n);
        int ans = 0;
        dfs(n, used, ans, 1);
        return ans;
    }
};