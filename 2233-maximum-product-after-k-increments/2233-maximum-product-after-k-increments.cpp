class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num: nums){
            pq.push(num);
        }
        while(k--){
            int x = pq.top() + 1;
            pq.pop();
            pq.push(x);
        }
        long long prod = 1;
        long long MOD = 1e9 + 7;
        while(!pq.empty()){
            prod *= pq.top();
            pq.pop();
            prod = prod % MOD;
        }
        return prod;
    }
};