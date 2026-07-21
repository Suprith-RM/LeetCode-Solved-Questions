class Solution {
public:
    string removeStars(string s) {
        int i = 0, n = s.size();
        string ans = "";
        while(i < n){
            while(i < n && s[i] != '*'){
                ans.push_back(s[i]);
                i++;
            }
            while(i < n && s[i] == '*'){
                ans.pop_back();
                i++;
            }
        }
        return ans;
    }
};