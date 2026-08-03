class Solution {
    void dfs(int node, unordered_map<int, vector<int>>& mp, vector<int>& ans, int parent){
        ans.push_back(node);
        for(auto& neigh: mp[node]){
            if(neigh == parent) continue;
            if(neigh != node){
                dfs(neigh, mp, ans, node);
            }
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        for(auto& edge: adjacentPairs){
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }
        int start = -1;
        for(const auto& it: mp){
            if(it.second.size() == 1){
                start = it.first;
                break;
            }
        }
        vector<int> ans;
        dfs(start, mp, ans, INT_MIN);
        return ans;
    }
};