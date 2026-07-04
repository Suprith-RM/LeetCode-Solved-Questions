class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(const auto& flight: flights){
            graph[flight[0]].push_back(make_pair(flight[1], flight[2]));
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        int minDist = INT_MAX;
        queue<pair<int, pair<int, int>>> q;
        q.push({src, {0, 0}});
        while(!q.empty()){
            int u = q.front().first;
            auto [cost, stops] = q.front().second;
            q.pop();
            if(stops <= k){
                for(auto neighbour: graph[u]){
                    int v = neighbour.first;
                    int wt_v = neighbour.second;
                    if(dist[v] > cost + wt_v){
                        dist[v] = cost + wt_v;
                        q.push({v, {dist[v], stops+1}});
                    }
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};