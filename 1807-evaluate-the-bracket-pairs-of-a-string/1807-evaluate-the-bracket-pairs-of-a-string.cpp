class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& know : knowledge) {
            mp[know[0]] = know[1];
        }
        string ans;
        int i = 0, n = s.size();
        while (i < n) {
            if (s[i] == '(') {
                i++;
                string temp = "";
                while (s[i] != ')') {
                    temp.push_back(s[i++]);
                }

                string addon = (mp.find(temp) == mp.end()) ? "?" : mp[temp];
                ans += addon;
                i++;
            } else
                ans.push_back(s[i++]);
        }
        return ans;
    }
};