class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        long long ans = 0;
        int len = log10(n);
        long long sum = 0;
        while(n){
            int digit = n / pow(10, len);
            if(digit != 0){
                ans = ans * 10 + digit;
                sum = sum + digit;
            }
            n -= pow(10, len) * digit;
            len--;
        }
        return ans * sum;
    }
};