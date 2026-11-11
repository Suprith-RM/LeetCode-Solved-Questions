class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans1 = 1LL * max(need1, need2) * (1LL * costBoth);

        long long diff2 = 1LL * max(0, need1 - need2);
        long long ans2 = 1LL * diff2 * cost1;
        ans2 += (1LL * costBoth * need2);

        long long diff3 = 1LL * max(0, need2 - need1);
        long long ans3 = 1LL * diff3 * cost2;
        ans3 += (1LL * costBoth * need1);

        long long ans4 = (1LL * need1 * cost1) + (1LL * need2 * cost2);
        return min(ans1, min(ans2, min(ans3, ans4)));
    }
};