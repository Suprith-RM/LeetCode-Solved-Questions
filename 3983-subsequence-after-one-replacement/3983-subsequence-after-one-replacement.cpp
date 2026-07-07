class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = t.size();
        int m = s.size();
        if (m > n) return false;
        vector<int> pref(n , 0);
        vector<int> suff(n , 0);
        int pr = 0, su = 0;
        int idx = 0;
        for(int i = 0; i < n; ++i){
            if(idx < m && t[i] == s[idx]){
                pr++;
                pref[i] = pr;
                idx++;
            }
        }
        idx = m-1;
        for(int i = n-1; i >= 0; --i){
            if(idx >= 0 && t[i] == s[idx]){
                su++;
                suff[i] = su;
                idx--;
            }
        }
        for(int i = 0; i < n; ++i){
            if(i == 0){
                pr = 0;
            }
            else{
                pr = max(pr, pref[i-1]);
            }
            if(pref[i] == 0 && suff[i] == 0){
                if(pr + su + 1 >= m) return true;
            }
            else if(pr + su >= m) return true;
            if(suff[i] != 0) su--;
        }
        return false;
    }
};