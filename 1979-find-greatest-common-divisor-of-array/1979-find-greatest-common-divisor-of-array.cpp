class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int num: nums){
            maxi = max(maxi, num);
            mini = min(mini, num);
        }
        return gcd(maxi, mini);
    }
};