class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return (long long) s;
        long long res = s * 1LL;
        n--;
        if(n % 2 != 0){
            res = res + (1LL * (n/2 + 1) * m) - (1LL * n/2);
        } else{
            res = res + (1LL * (n/2) * (m-1)) + 1;
        }
        return res;
    }
};