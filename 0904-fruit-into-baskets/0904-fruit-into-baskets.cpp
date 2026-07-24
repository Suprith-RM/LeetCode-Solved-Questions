class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int n = fruits.size(), uniques = 0, j = 0, len = 0;
        for(int i = 0; i < n; ++i){
            if(mp[fruits[i]] == 0) uniques++;
            mp[fruits[i]]++;
            while(j <= i && uniques > 2){
                mp[fruits[j]]--;
                if(mp[fruits[j]] == 0) uniques--;
                j++;
            }
            if(uniques <= 2) len = max(len, i - j + 1);
        }
        return len;
    }
};