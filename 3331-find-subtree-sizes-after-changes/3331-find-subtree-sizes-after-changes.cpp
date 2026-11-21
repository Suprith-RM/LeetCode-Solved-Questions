class Solution {
    void dfs1(int node, vector<vector<int>>& graph,
              string& s, vector<int>& last,
              vector<int>& newParent) {
        int idx = s[node] - 'a';
        int prev = last[idx];
        if (prev != -1) {
            newParent[node] = prev;
        }
        last[idx] = node;
        for (int child : graph[node]) {
            dfs1(child, graph, s, last, newParent);
        }
        last[idx] = prev;
    }
    void dfs2(int node, vector<vector<int>>& graph,
              vector<int>& ans) {
        ans[node] = 1;
        for (int child : graph[node]) {
            dfs2(child, graph, ans);
            ans[node] += ans[child];
        }
    }
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> graph(n);
        for (int i = 1; i < n; i++) {
            graph[parent[i]].push_back(i);
        }
        vector<int> last(26, -1);
        vector<int> newParent = parent;
        dfs1(0, graph, s, last, newParent);
        vector<vector<int>> newGraph(n);
        for (int i = 1; i < n; i++) {
            newGraph[newParent[i]].push_back(i);
        }
        vector<int> ans(n, 0);
        dfs2(0, newGraph, ans);
        return ans;
    }
};