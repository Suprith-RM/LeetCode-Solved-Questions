class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int n = s.size(), j = 0, maxFreq = 0, ans = 0;
        for(int i = 0; i < n; ++i){
            char ch = s[i];
            freq[ch-'A']++;
            maxFreq = max(maxFreq, freq[ch-'A']);
            while ((i - j + 1) - maxFreq > k) {
                freq[s[j] - 'A']--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};