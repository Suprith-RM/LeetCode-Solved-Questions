
class Solution {
    void bfs(int node, unordered_map<int, vector<int>>& mp, vector<bool>& vis, string& ans, string& s) {
        vector<char> alpha;
        vector<int> pos;
        queue<int> q;
        q.push(node);
        vis[node] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            alpha.push_back(s[curr]);
            pos.push_back(curr);
            for (auto& neigh : mp[curr]) {
                if (!vis[neigh]) {
                    q.push(neigh);
                    vis[neigh] = true;
                }
            }
        }
        sort(alpha.begin(), alpha.end());
        sort(pos.begin(), pos.end());
        for (int i = 0; i < pos.size(); ++i) {
            ans[pos[i]] = alpha[i];
        }
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> mp;
        for (auto& pair : pairs) {
            mp[pair[0]].push_back(pair[1]);
            mp[pair[1]].push_back(pair[0]);
        }
        string ans = s;
        vector<bool> vis(s.size(), false);
        for (int i = 0; i < s.size(); ++i) {
            if (!vis[i]) {
                bfs(i, mp, vis, ans, s);
            }
        }
        return ans;
    }
};
