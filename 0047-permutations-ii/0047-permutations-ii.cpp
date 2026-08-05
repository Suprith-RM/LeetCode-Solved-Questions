class Solution {
    void permutes(vector<int>& nums, vector<vector<int>>& ans, int idx){
        if(idx >= nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for(int i = idx; i < nums.size(); ++i){
            if(used.count(nums[i])) continue;
            used.insert(nums[i]);
            swap(nums[i], nums[idx]);
            permutes(nums, ans, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        permutes(nums, ans, 0);
        return ans;
    }
};