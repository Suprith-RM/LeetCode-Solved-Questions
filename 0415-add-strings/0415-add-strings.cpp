class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0, i = num1.size()-1, j = num2.size()-1;
        string ans = "";
        while(carry || i >= 0 || j >= 0 ){
            int sum = 0;
            if(i >= 0){
                sum += num1[i] - '0';
                i--;
            } 
            if(j >= 0){
                sum += num2[j] - '0';
                j--;
            }
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            ans = to_string(sum) + ans;
        }
        return ans;
    }
};