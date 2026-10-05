class Solution {
public:
    int scoreOfParentheses(string s) {
        int op = 0, ans = 0, n = s.size(), i = 0;
        while(i < n){ 
            if(s[i] == '('){
                op++;
                i++;
            }
            else{
                ans += pow(2, op-1);
                while(i < n && s[i] == ')'){
                    op--;
                    i++;
                }
            }
        }
        return ans;
    }
};