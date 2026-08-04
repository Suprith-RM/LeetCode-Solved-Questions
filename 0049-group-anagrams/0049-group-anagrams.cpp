class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string &s : strs) {
            vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string key;
        for (int x : freq) {
            key += "#" + to_string(x);
        }
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& [key, val] : mp){
            ans.push_back(val);
        }
        return ans;
    }
};