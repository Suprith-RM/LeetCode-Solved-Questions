class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> graph(n);
        for(const auto& red: redEdges){
            graph[red[0]].push_back({red[1], 0});
        }
        for(const auto& blue: blueEdges){
            graph[blue[0]].push_back({blue[1], 1});
        }
        vector<int> dist(n, -1);
        vector<vector<bool>> vis(n, vector<bool>(2, false));
        vis[0][0] = true, vis[0][1] = true;
        dist[0] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 1}});
        q.push({0, {0, 0}});
        while(!q.empty()){
            int dist_u = q.front().first;
            auto [u, prev] = q.front().second;
            q.pop();
            if(dist[u] == -1) dist[u] = dist_u;
            for(auto neigh: graph[u]){
                int v = neigh.first;
                int clr = neigh.second;
                if(!vis[v][clr] && clr != prev){
                    vis[v][clr] = true;
                    q.push({dist_u + 1, {v, clr}});
                }
            }
        }
        return dist;
    }
};