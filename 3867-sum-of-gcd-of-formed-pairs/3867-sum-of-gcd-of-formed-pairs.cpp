class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size(), mx = INT_MIN;
        for(int i = 0; i < n; ++i){
            if(nums[i] > mx) mx = nums[i];
            nums[i] = gcd(mx, nums[i]);
        }
        sort(nums.begin(), nums.end());
        int l = 0, h = n-1;
        long long res = 0;
        while(l < h){
            res += gcd(nums[h], nums[l]);
            l++, h--;
        }
        return res;
    }
};