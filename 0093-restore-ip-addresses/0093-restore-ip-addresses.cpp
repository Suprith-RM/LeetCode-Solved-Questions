class Solution {
    void helper(string& s, vector<string>& ans, string& temp, int idx, int cnt){
        if(cnt > 4) return;
        
        if(idx >= s.size() && cnt == 4){
            temp.pop_back();
            ans.push_back(temp);
            temp.push_back('.');
            return;
        }
        
        for(int i = idx; i < idx + 3 && i < s.size(); ++i){
            string x = s.substr(idx , i - idx + 1);
            if(i > idx && s[idx] == '0'|| stoi(x) > 255) return;
            int len = temp.size();
            
            temp += x;
            temp.push_back('.');
            helper(s, ans, temp, i + 1, cnt + 1);
            while(temp.size() != len) temp.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        string temp;
        vector<string> ans;
        helper( s, ans, temp, 0, 0);
        return ans;
    }
};