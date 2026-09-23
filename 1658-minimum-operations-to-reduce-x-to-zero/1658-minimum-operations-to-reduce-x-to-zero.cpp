class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum = 0;
        for(int num: nums) sum += num;
        sum -= x;
        int i = 0, n = nums.size(), len = -1;
        for(int j = 0; j < n; ++j){
            sum -= nums[j];
            while(i < n && sum < 0){
                sum += nums[i++];
            }
            if(sum == 0) len = max(len, j - i + 1);
        }
        return len == -1 ? len : (n - len);
    }
};