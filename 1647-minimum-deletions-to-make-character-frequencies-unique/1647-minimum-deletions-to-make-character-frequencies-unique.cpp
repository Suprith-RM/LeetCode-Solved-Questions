class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        int maxi = 0;
        for(char ch: s){
            freq[ch-'a']++;
            maxi = max(maxi, freq[ch-'a']);
        }
        vector<bool> taken(maxi + 1, false);
        sort(freq.begin(), freq.end());
        int i = 25, cnt = 0;
        while(i >= 0 && freq[i] > 0){
            while(freq[i] > 0 && taken[freq[i]]){
                freq[i]--;
                cnt++;
            }
            if(freq[i] > 0) taken[freq[i]] = true;
            i--;
        }
        return cnt;
    }
};