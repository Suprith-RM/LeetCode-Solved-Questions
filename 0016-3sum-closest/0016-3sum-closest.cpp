class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0, diff = INT_MAX;
        for(int k = nums.size()-1; k >=2; --k){
            int i = 0, j = k - 1;
            while(i < j){
                int sum = (nums[k] + nums[i] + nums[j]);
                if(diff > abs(target - sum)){
                    diff = abs(target - sum);
                    ans = sum;
                }
                if(sum >= target){
                    int curr = nums[j];
                    while(j > i && nums[j] == curr) j--;
                }
                else{
                    int curr = nums[i];
                    while (i < j && nums[i] == curr) i++;
                }
            }
        }
        return ans;
    }
};