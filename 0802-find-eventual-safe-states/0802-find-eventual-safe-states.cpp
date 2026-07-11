class Solution {
    bool dfs(vector<vector<int>>& graph, int node, vector<int> &dp){
        if(dp[node] != 0) return dp[node] == 2;
        dp[node] = 1;
        for(auto neighbour: graph[node]){
            if(!dfs(graph, neighbour, dp)) return false;
        }
        dp[node] = 2;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> dp(n);
        vector<int> ans;
        for(int i = 0; i < n; ++i){
           if(dfs(graph, i, dp)) ans.push_back(i);
        }
        return ans;
    }
};