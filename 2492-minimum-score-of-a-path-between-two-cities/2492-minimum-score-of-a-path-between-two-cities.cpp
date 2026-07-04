class Solution {
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
        vector<int> dist(n+1, INT_MAX);
        dist[1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, 1 });
        int ans = INT_MAX;
        while(!pq.empty()){
            auto [wt , u] = pq.top();
            pq.pop();
            if(dist[u] < wt) continue;
            for(auto &neighbour : graph[u]){
                int v = neighbour.first;
                int w = neighbour.second;
                ans = min(w, ans);
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({ dist[v], v});
                }
            }
        }
        return ans;
    }
};