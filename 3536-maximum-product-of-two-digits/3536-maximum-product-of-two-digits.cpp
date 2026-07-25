class Solution {
public:
    int maxProduct(int n) {
        int max_1 = INT_MIN, max_2 = INT_MIN; 
        while(n > 0){
            int digit = n % 10;
            if(digit > max_1){
                max_2 = max_1;
                max_1 = digit;
            }
            else if(digit > max_2){
                max_2 = digit;
            }
            n /= 10;
        }
        return max_1 * max_2;
    }
};