class Solution {
    bool isSet(vector<int>& freq, vector<int>& check){
        for(int i = 0; i < 128; ++i){
            if(check[i] < freq[i]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m > n) return "";
        vector<int> freq(128, 0);
        vector<int> freq_check(128, 0);
        for(char ch: t){
            freq[ch]++;
        }
        pair<int, int> pr = { -1, n };
        int j = 0;
        for(int i = 0; i <= n - m; ++i){
            while(j < n && !isSet(freq, freq_check)){
                freq_check[s[j]]++;
                j++;
            }
            if(j - i < pr.second - pr.first && isSet(freq, freq_check)) pr = {i , j};
            freq_check[s[i]]--;
        }
        if(pr.first == -1) return "";
        return  s.substr(pr.first, pr.second - pr.first);
    }
};