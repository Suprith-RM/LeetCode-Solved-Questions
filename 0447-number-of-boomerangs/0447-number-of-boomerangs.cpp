class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> mp;
            for (int j = 0; j < n; ++j) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int dist = dx * dx + dy * dy; 
                mp[dist]++;
            }
            for (auto [k, v] : mp) {
                ans += (v * (v - 1));
            }
        }
        return ans;
    }
};