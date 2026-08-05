class Solution {
    void mark_infected(int node, vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& infected){
        vis[node] = true;
        infected[node] = true;
        for(auto& neighbour: graph[node]){
            if(!vis[neighbour]){
                mark_infected(neighbour, graph, vis, infected);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for(auto& edge: invocations){
            graph[edge[0]].push_back(edge[1]);
        }
        vector<bool> infected(n, false);
        vector<bool> vis(n, false);
        bool dependency = false;
        mark_infected(k, graph, vis, infected);
        for(int node = 0; node < n; ++node){
            if(dependency) break;
            for(auto& neighbour: graph[node]){
                if(!infected[node] && infected[neighbour]){
                    dependency = true;
                    break;
                }
            }
        }
        vector<int> ans;
        if(dependency){
            for(int i = 0; i < n; ++i) ans.push_back(i);
            return ans;
        }
        for(int i = 0; i < n; ++i){
            if(!infected[i]) ans.push_back(i);
        }
        return ans;
    }
};