class Solution {
    void dfs(vector<int>& edges, int node, vector<bool>& vis,
             vector<int>& dist, int d = 0) {
        vis[node] = true;
        dist[node] = d;
        if (edges[node] == -1 || vis[edges[node]])
            return;
        dfs(edges, edges[node], vis, dist, d + 1);
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<bool> vis1(n, false), vis2(n, false);
        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
        dfs(edges, node1, vis1, dist1);
        dfs(edges, node2, vis2, dist2);
        int ans = -1;
        int best = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dist1[i] == INT_MAX || dist2[i] == INT_MAX)
                continue;
            int curr = max(dist1[i], dist2[i]);
            if (curr < best) {
                best = curr;
                ans = i;
            }
        }
        return ans;
    }
};