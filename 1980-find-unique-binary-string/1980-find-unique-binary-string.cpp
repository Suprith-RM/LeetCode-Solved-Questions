class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size(), m = nums[0].size(), j = 0;
        string ans = "";
        for(int i = 0; i < n; ++i){
            int x = nums[i][j++] - '0';
            ans += (!x + '0');
        }
        return ans;
    }
};