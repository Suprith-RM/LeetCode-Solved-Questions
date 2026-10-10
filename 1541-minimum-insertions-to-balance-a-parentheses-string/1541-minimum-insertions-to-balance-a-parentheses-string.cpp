class Solution {
public:
    int minInsertions(string s) {
        int ans = 0, op = 0, n = s.size();
        for(int i = 0; i < n; ++i){ 
            char ch = s[i];
            if(ch == '(')
                op++;
            else{
                op--;
                if((i < n-1 && s[i+1] != ')') || i == n-1){
                    ans++;
                }
                else if(i < n-1 && s[i+1] == ')'){
                    i++;
                }
            }
            if(op < 0){
                ans++;
                op = 0;
            }
                
        }
        ans += 2*abs(op);
        return ans;
    }
};