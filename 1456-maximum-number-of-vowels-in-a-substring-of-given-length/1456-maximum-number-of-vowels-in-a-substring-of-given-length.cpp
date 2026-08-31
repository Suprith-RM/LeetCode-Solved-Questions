class Solution {
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    int maxVowels(string s, int k) {
        int cnt = 0, ans = 0, n = s.size();
        for(int i = 0; i < k; ++i){
            if(isVowel(s[i])){
                cnt++;
                ans = max(ans, cnt);
            }
        }
        for(int i = k; i < n; ++i){
            if(isVowel(s[i])) cnt++;
            if(isVowel(s[i-k])) cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};