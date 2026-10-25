class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> seen;
        vector<int> ans;
        int n = nums.size(), k = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] == -1){
                k++;
                if(k > seen.size())
                    ans.push_back(-1);
                else
                    ans.push_back(seen[seen.size() - k]);
            }
            else{
                k = 0;
                seen.push_back(nums[i]);
            }
        }
        return ans;
    }
};