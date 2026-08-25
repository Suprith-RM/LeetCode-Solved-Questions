class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        for(int num: nums){
            if(num % k == 0) st.insert(num);
        }
        for(int i = 1; i <= n+1; ++i){
            if(st.count(i * k) == 0) return i * k;
        }
        return -1;
    }
};