class Solution {
    void dfs(vector<vector<pair<int,int>>> &graph, int node, vector<bool> &vis, int &ans){
        vis[node] = true;
        for(auto [next, wt]: graph[node]){
            ans = min(ans, wt);
            if(!vis[next]){
                dfs(graph, next, vis, ans);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n + 1);
        for(const auto& road: roads){
            int u = road[0];
            int v = road[1];
            int wt = road[2];
            graph[u].push_back({ v, wt });
            graph[v].push_back({ u, wt });
        }
        vector<bool> vis(n+1, false);
        int ans = INT_MAX;
        dfs(graph, 1, vis, ans);
        return ans;
    }
};