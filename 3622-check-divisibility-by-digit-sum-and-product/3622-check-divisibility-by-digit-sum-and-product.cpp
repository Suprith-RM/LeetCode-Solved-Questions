class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1, fin = 0, temp = n;
        while(n > 0){
            int digit = n % 10;
            sum += digit;
            prod *= digit;
            n /= 10;
        }
        fin = sum + prod;
        return (temp % fin == 0);
    }
};