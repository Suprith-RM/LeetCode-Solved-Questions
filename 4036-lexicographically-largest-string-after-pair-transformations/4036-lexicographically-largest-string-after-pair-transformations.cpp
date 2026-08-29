class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for (int x : nums) {
            string s;
            for (int i = 25; i >= 0; i--) {
                int power = 1 << i;

                while (x >= power) {
                    x -= power;
                    s += char('a' + i);
                }
            }

            ans.push_back(s);
        }

        return ans;
    }
};