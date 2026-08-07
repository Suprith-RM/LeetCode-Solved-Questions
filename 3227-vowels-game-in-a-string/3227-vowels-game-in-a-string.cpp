class Solution {
public:
    bool doesAliceWin(string s) {
        int vow = 0;
        for(char ch: s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ) vow++;
        }
        if(vow == 0) return false;
        return true;
    }
};