class Solution {

public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size(), i = 0, ones = 0;
        string ans = "-";
        for(int j = 0; j < n; ++j){
            if(s[j] == '1') ones++;
            while(i < n && ones > k || s[i] == '0'){
                if(s[i] == '1') ones--;
                i++;
            }
            if(ones == k){
                string curr_window = s.substr(i, j - i + 1);
                if(curr_window.size() < ans.size() || ans == "-") ans = curr_window;
                else if(curr_window.size() == ans.size()){
                    ans = min(ans, curr_window);
                }
            } 
        }
        return ans == "-" ? "" : ans;
    }
};