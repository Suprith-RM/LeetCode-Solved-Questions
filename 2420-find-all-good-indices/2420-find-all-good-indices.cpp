class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int time) {
        int cont = 0, n = nums.size();
        vector<int> inc(n, 0);
        vector<int> dec(n, 0);
        for(int i = 1; i < n; ++i){
            if(nums[i] >= nums[i-1])
                cont++;
            else cont = 0;
            inc[i] = cont;
        }
        cont = 0;
        for(int i = n-2; i >= 0; --i){
            if(nums[i] >= nums[i+1])
                cont++;
            else cont = 0;
            dec[i] = cont;
        }
        vector<int> ans;
        for(int i = time; i < n - time; ++i){
            if(inc[i + time] - inc[i+1] == time-1  && dec[i - time] - dec[i-1] == time-1)
                ans.push_back(i);
        }
        return ans;
    }
};