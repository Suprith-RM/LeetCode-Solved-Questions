class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, bonus = 0;
        for(char ch: s){
            if(ch == '(')
                ans++;
            else 
                ans--;
            if(ans < 0 && ch == ')'){
                bonus++;
                ans++;
            }
        }
        return abs(ans + bonus);
    }
};