class Solution {
    bool check(vector<int>& freq, int k){
        int tot = 0, maxi = INT_MIN;
        for(int num: freq){
            tot += num;
            if(num > maxi){
                maxi = num;
            }
        }
        return (tot - maxi <= k);
    }
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int extras = 0, n = s.size(), j = 0, ans = 0;
        for(int i = 0; i < n; ++i){
            char ch = s[i];
            freq[ch-'A']++;
            while(j <= i && !check(freq, k)){
                freq[s[j]-'A']--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};