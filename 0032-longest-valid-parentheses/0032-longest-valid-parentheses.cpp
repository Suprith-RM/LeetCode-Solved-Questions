class Solution {
public:
    int longestValidParentheses(string s) {
        int op = 0, cl = 0, n = s.size(), ans = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '(')
                op++;
            else{
                cl++;
            }
            if(op == cl){
                ans = max(ans, op*2);
            }
            if(cl > op){
                cl = 0, op = 0;
            }
        }
        op = 0, cl = 0;
        for(int i = n-1; i >= 0; --i){
            if(s[i] == ')')
                op++;
            else{
                cl++;
            }
            if(op == cl){
                ans = max(ans, op*2);
            }
            if(cl > op){
                cl = 0, op = 0;
            }
        }
        return ans;
    }
};