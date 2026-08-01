class Solution {
    void flip(vector<int>& nums, int i){
        for(int j = i; j < i + 3; ++j){
            if(nums[j] == 0) nums[j] = 1;
            else nums[j] = 0;
        }
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n - 3; ++i){
            if(nums[i] == 0){
                flip(nums, i);
                cnt++;
            }
        }
        int lst = (nums[n-1] + nums[n-2] + nums[n-3]);
        if(lst == 0) return cnt + 1;
        if(lst == 3) return cnt;
        return -1;
    }
};