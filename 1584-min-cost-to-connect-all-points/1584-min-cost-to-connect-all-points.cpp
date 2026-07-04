class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> mstSet(n, false);
        int src = 0, cost = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push( {0, src} );
        while(!pq.empty()){
            auto [wt, u] = pq.top();
            pq.pop();
            if(!mstSet[u]){
                mstSet[u] = true;
                cost += wt;
                for(int v = 0; v < n; v++){
                    if(!mstSet[v]){
                        pq.push({abs(points[u][0] - points[v][0]) +
                        abs(points[u][1] - points[v][1]), v});
                    }
                }
            }
        }
        return cost;
    }
};