class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n);
        vector<vector<int>> rev(n);
        for(int u = 0; u < n; ++u){
            outdegree[u] = graph[u].size();
            for(int v : graph[u]){
                rev[v].push_back(u);
            }
        }
        queue<int> q;
        for(int i = 0; i < n; ++i){
            if(outdegree[i] == 0) 
                q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto p: rev[u]){
                outdegree[p]--;
                if(outdegree[p] == 0) q.push(p);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            if(outdegree[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};