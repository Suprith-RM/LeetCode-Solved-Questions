class Solution {
    int update(vector<int> &freq){
        int maxi = INT_MIN, mini = INT_MAX;
        for(int num: freq){
            if(num != 0){
                mini = min(mini, num);
                maxi = max(maxi, num);
            }
        }
        return maxi - mini;
    }
public:
    int beautySum(string s) {
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; ++i){
            vector<int> freq(26, 0);
            for(int j = i; j < n; ++j){
                freq[s[j]-'a']++;
                ans += update(freq);
            }
        }
        return ans;
    }
};