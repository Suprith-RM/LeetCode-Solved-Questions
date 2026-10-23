
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size(), ans = -1;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i] || nums[i] == i)
                continue;
            int cyclicAnd = nums[i];
            int curr = nums[i];
            while (!visited[curr]) {
                visited[curr] = true;
                cyclicAnd &= curr;
                curr = nums[curr];
            }
            if (ans == -1)
                ans = cyclicAnd;
            else
                ans &= cyclicAnd;
        }

        return ans == -1 ? 0 : ans;
    }
};
