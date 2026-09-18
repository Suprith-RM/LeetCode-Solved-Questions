class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> freq(26, vector<int>(2, -1));
        for(int i = 0; i < n; ++i){
            if(freq[s[i]-'a'][0] == -1)
                freq[s[i]-'a'][0] = i;
            freq[s[i]-'a'][1] = i;
        }
        vector<vector<int>> intervals;
        for(auto& intv: freq){
            int l = intv[0], r = intv[1];
            if(l == -1)
                continue;
            bool valid = true;
            for(int i = l; i <= r; ++i){
                if(freq[s[i]-'a'][0] != -1 && freq[s[i]-'a'][0] < l){
                    valid = false;
                    break;
                }
                r = max(r, freq[s[i]-'a'][1]);
            }
            if(valid)
                intervals.push_back({l, r});
        }
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int curr = -1;
        vector<string> ans;
        for(auto& intv: intervals){
            if(intv[0] > curr){
                ans.push_back(s.substr(intv[0], intv[1] - intv[0] + 1));
                curr = intv[1];
            }
        }
        return ans;
    }
};