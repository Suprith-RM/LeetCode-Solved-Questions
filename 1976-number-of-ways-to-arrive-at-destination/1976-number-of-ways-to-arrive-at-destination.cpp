class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9+7;
        vector<vector<pair<int, long long>>> graph(n);
        for(const auto& road: roads){
            int u = road[0];
            int v = road[1];
            long long dist = road[2];
            graph[u].push_back({v, dist});
            graph[v].push_back({u, dist});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        std::priority_queue<pair<long long, int>, std::vector<pair<long long, int>>, std::greater<pair<long long, int>>> pq;
        pq.push({dist[0], 0});
        while(!pq.empty()){
            auto [dist_u, u] = pq.top();
            pq.pop();
            if(dist_u > dist[u]) continue;
            for(auto [v, dist_v]: graph[u]){
                if(dist[v] == dist_v + dist_u)
                    ways[v] = (ways[v] + ways[u]) % MOD;
                else if(dist[v] > dist_v + dist_u){
                    dist[v] = dist_v + dist_u;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
            }
        }
        return ways[n-1] % MOD;
    }
};