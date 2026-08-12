class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size(), m = t.size();
        int i = n - 1, j = m - 1, p = i, q = j;
        while(p >= 0){
            int skip = 0;
            while(p >= 0 && (s[p] == '#' || skip > 0)){
                if(s[p] == '#')skip++;
                else skip--;
                p--;
            }
            p -= skip;
            if(p >= 0 && s[p] != '#'){
                swap(s[p], s[i]);
                p--, i--;
            } 
        }
        while(q >= 0){
            int skip = 0;
            while(q >= 0 && (t[q] == '#' || skip > 0)){
                if(t[q] == '#')skip++;
                else skip--;
                q--;
            }
            q -= skip;
            if(q >= 0 && t[q] != '#'){
                swap(t[q], t[j]);
                q--, j--;
            }
        }
        if(n - i != m - j) return false;
        i++, j++;
        while(i < n) if(s[i++] != t[j++]) return false;
        return true;
    }
};