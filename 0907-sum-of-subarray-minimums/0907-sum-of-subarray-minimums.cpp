class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        vector<int> pse(n);
        stack<int> s1;
        stack<int> s2;
        for(int i = 0; i < n; ++i){
            while(!s1.empty() && arr[s1.top()] >= arr[i]) s1.pop();
            if(s1.empty()) pse[i] = -1;
            else pse[i] = s1.top();
            s1.push(i);
        }
        for(int i = n-1; i >= 0; --i){
            while(!s2.empty() && arr[s2.top()] > arr[i]) s2.pop();
            if(s2.empty()) nse[i] = n;
            else nse[i] = s2.top();
            s2.push(i);
        }
        long long ans = 0;
        const int MOD = 1e9+7;
        for(int i = 0; i < n; ++i){
            long long factor = (1LL * arr[i]) * (1LL * nse[i] - 1LL * i) * (1LL * i - 1LL * pse[i]);
            ans = (ans + factor) % MOD;
        }
        return (int)(ans);
    }
};