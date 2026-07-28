class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string ans = s.substr(0, (n / 2));
        sort(ans.begin(), ans.end());
        string scnd = ans;
        reverse(scnd.begin(), scnd.end());
        if(n % 2 != 0){
            ans.push_back(s[n/2]);
        }
        ans = ans + scnd;
        return ans;
    }
};