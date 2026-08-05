class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        vector<int> freq(26, 0);
        for(int i = 0; i < n; ++i){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        int ans = 0;
        for(int num: freq){
            ans += abs(num);
        }
        return ans / 2;
    }
};