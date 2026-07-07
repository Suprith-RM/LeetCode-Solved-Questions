class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len = s1.size();
        int n = s2.size();
        vector<int> need(26, 0), window(26, 0);
        int requirement = 0;
        for(char ch: s1){
            if(need[ch-'a'] == 0) requirement++;
            need[ch-'a']++;
        }
        bool formed = false;
        int set = 0, l = 0;
        for(int r = 0; r < n; ++r){
            window[s2[r] - 'a']++;
            if(window[s2[r]-'a'] == need[s2[r] - 'a']){
                set++;
            }
            while(set == requirement){
                if(r - l + 1 == len){
                    formed = true;
                }
                window[s2[l] - 'a']--; 
                if(window[s2[l] - 'a'] < need[s2[l] - 'a']) set --;
                l++;
            }
        }
        return formed;
    }
};