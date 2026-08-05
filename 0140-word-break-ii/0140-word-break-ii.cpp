class Solution {
    void dfs(int idx, string &s, unordered_set<string> &dict,
         string curr, vector<string> &ans) {
    if (idx == s.size()) {
        curr.pop_back();          
        ans.push_back(curr);
        return;
    }
    string word;
    for (int i = idx; i < s.size(); i++) {
        word += s[i];
        if (dict.count(word)) {
            dfs(i + 1, s, dict, curr + word + " ", ans);
        }
    }
}
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto& str: wordDict){
            dict.insert(str);
        }
        vector<string> ans;
        string temp = "";
        dfs(0, s, dict, temp, ans);
        return ans;
    }
};