class Solution {
    void helper(string& s, string temp, int idx, vector<string>& ans){
        while(s[idx] <= '9' && s[idx] >= '0') idx++;
        if(idx >= s.size()){
            ans.push_back(temp);
            return;
        }
        // LowerCase
        temp[idx] = tolower(temp[idx]);
        helper(s, temp, idx+1, ans);
        // UpperCase
        temp[idx] = toupper(temp[idx]);
        helper(s, temp, idx+1, ans);
    }
public:
    vector<string> letterCasePermutation(string s) {
        string temp = s;
        vector<string> ans;
        helper(s, temp, 0, ans);
        return ans;
    }
};