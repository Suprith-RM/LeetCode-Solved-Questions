class Solution {
public:
    int findMinMoves(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int num: nums){
            sum += num;
        }
        if(sum % n != 0) return -1;
        int avg = sum / n;
        int ans = INT_MIN, bal = 0;
        for(int i = 0; i < n-1; ++i){
            bal += nums[i] - avg;
            ans = max(ans, abs(bal));
            ans = max(ans, nums[i] - avg);
        } 
        return (ans == INT_MIN) ? 0 : ans;
    }
};