class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        int i = 0;
        for(const auto& edge: edges){
            graph[edge[0]].push_back({edge[1], succProb[i]});
            graph[edge[1]].push_back({edge[0], succProb[i]});
            i++;
        }
        vector<double> prob(n, 0);
        prob[start_node] = 1;
        priority_queue<pair<double, int>> pq;
        pq.push({prob[start_node], start_node});
        while(!pq.empty()){
            auto [prob_u, u] = pq.top();
            pq.pop();
            if(prob[u] > prob_u) continue;
            for(auto [v, prob_v]: graph[u]){
                if(prob[v] < prob_u * prob_v){
                    prob[v] = prob_u * prob_v;
                    pq.push({prob[v], v});
                } 
            }
        }
        return prob[end_node];
    }
};