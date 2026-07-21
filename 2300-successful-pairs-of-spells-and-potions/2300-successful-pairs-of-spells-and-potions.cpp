class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<pair<int,int>> spl;
        int len = spells.size(); 
        for(int i = 0; i < len; ++i){
            spl.push_back({spells[i], i});
        }
        vector<int> ans(len, 0);
        sort(potions.begin(), potions.end());
        sort(spl.begin(), spl.end());
        int i = len - 1;
        for(int j = 0, len2 = potions.size(); j < len2; ++j){
            while(i >= 0 && 1LL * spl[i].first * potions[j] >= success){
                ans[spl[i].second] = (len2 - j);
                i--;
            }
        }
        return ans;
    }
};