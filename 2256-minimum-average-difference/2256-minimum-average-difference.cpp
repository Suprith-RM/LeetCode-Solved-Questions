class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n, 0);
        pref[0] = nums[0];
        long long diff = LONG_MAX;
        int ans = -1;
        for(int i = 1; i < n; ++i){
            pref[i] = nums[i] + pref[i-1];
        }
        for(int i = 0; i < n; ++i){
            long long lftAvg = (pref[i] / (i+1));
            long long rgtAvg = 0;
            if(i < n-1) rgtAvg = (pref[n-1] - pref[i])/(n-i-1);
            long long dif = abs(rgtAvg - lftAvg);
            if(dif < diff){
                diff = dif;
                ans = i;
            } 
        }
        return ans;
    }
};