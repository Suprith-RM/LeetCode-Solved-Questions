class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(const auto& time: times){
            graph[time[0]].push_back({time[1], time[2]});
        }
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        pq.push({dist[k], k});
        while(!pq.empty()){
            auto [dist_u, u] = pq.top();
            pq.pop();
            if(dist_u > dist[u]) continue;
            for(auto [v, dist_v]: graph[u]){
                if(dist[v] > dist_u + dist_v){
                    dist[v] = dist_u + dist_v;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i <= n; ++i){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};