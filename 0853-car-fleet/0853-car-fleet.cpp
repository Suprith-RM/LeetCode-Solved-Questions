class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.push_back({position[i], speed[i]});
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        double time = 0;
        for (int i = n - 1; i >= 0; --i) {
            double t = (target - arr[i].first * 1.0) / arr[i].second;
            if (t > time) {
                ans++;
                time = t;
            }
        }
        return ans;
    }
};