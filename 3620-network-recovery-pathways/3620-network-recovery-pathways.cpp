class Solution {
    bool valid_dijkstra(vector<vector<pair<int, int>>> &graph, vector<bool>& online, int n, long long mid, long long k){
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        pq.emplace(0, 0);
        int mini = INT_MAX;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int wt_u = top.first;
            int u = top.second;
            if(wt_u > dist[u]) continue;
            for(auto& neighbour: graph[u]){
                int wt_v = neighbour.first;
                int v = neighbour.second;
                if(wt_v < mid) continue;
                if(v != n-1 && !online[v]) continue;
                if(dist[v] > dist[u] + wt_v * 1LL){
                    dist[v] = 1LL * dist[u] + wt_v;
                    if(dist[v] < mini){
                        mini = dist[v];
                    }
                    pq.push({dist[v], v});
                }
            }
        }
        return (dist[n-1] <= k);
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        long long l = 0, h = 0;
        vector<vector<pair<int, int>>> graph(n);
        for(const auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back({edge[2], v});
            h = max(h, edge[2] * 1LL);
        }
        int ans = -1;
        while(l <= h){
            long long mid = l + (h - l)/2;
            if(valid_dijkstra(graph, online, n, mid, k)){
                ans = mid;
                l = mid + 1;
            } 
            else h = mid - 1;
        }
        return ans;
    }
};