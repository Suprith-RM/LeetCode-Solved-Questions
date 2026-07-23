class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int cnt = 0, n = nums.size();
        for(int num: nums) 
            mp[num]++;

        if(k == 0){
            for(auto& [key, val]: mp){
                if(val >= 2) cnt++;
            }
        }else{
            for(auto& [key, val]: mp){
                if(mp.count(k + key)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};