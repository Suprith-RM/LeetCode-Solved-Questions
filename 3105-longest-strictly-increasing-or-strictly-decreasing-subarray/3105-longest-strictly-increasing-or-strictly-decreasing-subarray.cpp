class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, n = nums.size(), i = 0;
        while(i < n-1){
            int cnt = 1;
            if(nums[i] < nums[i+1]){
                while(i < n-1 && nums[i] < nums[i+1]){
                    i++;
                    cnt++;
                }
                ans = max(ans, cnt); 
            }
            else{
                i++;
            }
        }
        i = 0;
        while(i < n-1){
            int cnt = 1;
            if(nums[i] > nums[i+1]){
                while(i < n-1 && nums[i] > nums[i+1]){
                    i++;
                    cnt++;
                }
                ans = max(ans, cnt); 
            }
            else{
                i++;
            }
        }
    
        return ans;
    }
};