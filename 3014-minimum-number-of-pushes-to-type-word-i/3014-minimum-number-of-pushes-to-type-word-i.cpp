class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> freq(26);
        for(char ch: word){
            freq[ch-'a']++;
        }
        sort(freq.begin(), freq.end());
        int cnt = 0, uniques = 0;
        for(int i = 25; i >= 0; --i){
            if(freq[i] != 0){
                if(uniques < 8) cnt += freq[i];
                else if(uniques >= 8 && uniques < 16) cnt += freq[i] * 2;
                else if(uniques >= 16 && uniques < 24) cnt += freq[i] * 3;
                else cnt += freq[i] * 4;
                uniques++;
            }
        }
        return cnt;
    }
};