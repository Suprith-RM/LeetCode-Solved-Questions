class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        for(int i = 1; i < n; ++i){
            int j = nums[i-1] + 1; 
            while(j != nums[i]){
                ans.push_back(j);
                j++;
            }
        }
        return ans;
    }
};