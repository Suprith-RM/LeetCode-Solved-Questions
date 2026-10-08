class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int op = 0;
        for(char ch: s){
            
            if(ch == '('){
                if(op != 0){
                    ans.push_back(ch);
                }
                op++;
            }
                
            else{
                op--;
                if(op != 0){
                    ans.push_back(ch);
                }
            } 

        }
        return ans;
    }
};