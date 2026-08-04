class Solution {
public:
    int trailingZeroes(int n) {
        long long fact_5 = 5;
        long long fact_2 = 2;
        int ans_5 = 0;
        int ans_2 = 0;
        int ans_10 = 0;
        while(n / fact_5){
            ans_5 += floor(n / fact_5);
            fact_5 *= 5;
        }
        while(n / fact_2){
            ans_2 += floor(n / fact_2);
            fact_2 *= 2;
        }
        ans_10 = min(ans_5, ans_2);
        return ans_10;
    }
};