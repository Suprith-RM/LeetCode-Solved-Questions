class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> mp;
        long long ans = 0;
        for(const auto& it: rectangles){
            mp[(1.0 * it[0])/(1.0 * it[1])]++; 
        }
        for(auto& [key, val]: mp){
            ans += (1LL* val * (1LL * val -1))/2;
        }
        return ans;
    }
};