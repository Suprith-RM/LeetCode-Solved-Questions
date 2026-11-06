class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size(), cnt = 0;
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < n - i; ++j){
                if(nums[j] > nums[j+1]){
                    if(locked[j] == 1){
                        cnt++;
                        k--;
                        locked[j] = 0;
                    }
                        
                    if(locked[j+1] == 1){
                        cnt++;
                        k--;
                        locked[j+1] = 0;
                    }
                    if(k < 0)
                        return -1;
                    cnt++;
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        return cnt;
    }
};