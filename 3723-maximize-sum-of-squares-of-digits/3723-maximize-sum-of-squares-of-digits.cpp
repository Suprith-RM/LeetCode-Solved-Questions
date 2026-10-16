class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while(sum > 0 && num > 0){
            int digit = min(9, sum);
            ans += digit + '0';
            sum -= digit;
            num--;
        }
        if(sum > 0 && num == 0)
            return "";
        while(num--)
            ans += '0';
        return ans;
    }
};