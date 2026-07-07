class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int len = p.size();
        vector<int> need(26, 0), window(26, 0);
        int required = 0;
        for(char ch: p){
            if(need[ch-'a'] == 0) required++;
            need[ch-'a']++;
        }
        vector<int> ans;
        int formed = 0;
        for(int i = 0; i < n; ++i){
            int ch = s[i] - 'a';
            window[ch]++;
            if(window[ch] == need[ch]) formed++;
            if (formed == required){
                ans.push_back(i - len + 1);
            }
            if(i + 1 - len < 0) continue; 
            int left = s[i + 1-len] - 'a';
            
            if(window[left] == need[left]) formed--;
            window[left]--;
        }
        return ans;
    }
};