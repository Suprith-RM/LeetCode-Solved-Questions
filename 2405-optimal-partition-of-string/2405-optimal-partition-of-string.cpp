class Solution {
public:
    int partitionString(string s) {
        int cnt = 1;
        vector<int> freq(26, 0);
        for(char ch: s){
            freq[ch-'a']++;
            if(freq[ch-'a'] > 1){
                cnt++;
                memset(freq.data(), 0, 26 * sizeof(int));
                freq[ch-'a'] = 1;
            } 
        }
        return cnt;
    }
};