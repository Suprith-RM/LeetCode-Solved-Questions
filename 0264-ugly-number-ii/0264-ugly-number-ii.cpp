class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> seen;

        pq.push(1);
        seen.insert(1);

        for (int i = 0; i < n - 1; i++) {
            long long curr = pq.top();
            pq.pop();
            for (long long x : {2LL, 3LL, 5LL}) {
                long long next = curr * x;

                if (!seen.count(next)) {
                    seen.insert(next);
                    pq.push(next);
                }
            }
        }

        return pq.top();
    }
};