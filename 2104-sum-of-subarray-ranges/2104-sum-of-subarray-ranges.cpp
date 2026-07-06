class Solution {
    long long computer(vector<int>& nums, function<bool (int, int)> comp){
        long long ans = 0;
        vector<int> s;
        for(int i = 0, len = nums.size(); i <= len; ++i){
            while(!s.empty() && (i == len || comp(nums[s.back()], nums[i]))){
                int j = s.back(), k = s.size() < 2 ? -1 : s[s.size() - 2];
                ans += (long long)(i - j) * (j - k) * nums[j];
                s.pop_back();
            }
            s.push_back(i);
        }
        return ans;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return computer(nums, less<int>()) - computer(nums, greater<int>());
    }
};