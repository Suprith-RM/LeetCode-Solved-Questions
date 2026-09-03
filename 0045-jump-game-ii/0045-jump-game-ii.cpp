class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 1, n = nums.size(), currentEnd = nums[0], farthest = nums[0];
        if(n <= 1) return 0;
        for(int i = 1; i < n; ++i){
            if(currentEnd >= n-1) return jumps;
            farthest = max(i + nums[i], farthest);
            if(i == currentEnd){
                jumps++;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};