class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n); 
        vector<int> pge(n); 
        stack<int> st;
        for(int i = 0; i < n; ++i){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if(st.empty()) pge[i] = -1;
            else pge[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; --i){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(st.empty()) nse[i] = -1;
            else nse[i] = st.top();
            st.push(i);
        }
        int l = 0, r = -1;
        for(int i = 0; i < n; ++i){
            if(nse[i] != -1){
                l = i;
                break;
            } 
        }
        for(int i = n-1; i >= 0; --i){
            if(pge[i] != -1){
                r = i;
                break;
            } 
        }
        return (r - l + 1);
    }
};