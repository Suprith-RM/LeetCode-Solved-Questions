class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), end = 1 << n;
        vector<vector<int>> ans;
        for(int i = 0; i < end; ++i){
            int mask = (1 << n-1);
            vector<int> temp;
            for(int j = 0; j < n; ++j){
                if(i & mask){
                    temp.push_back(nums[j]);
                }
                mask >>= 1;
            }
            ans.push_back(temp);
        } 
        return ans;
    }
};