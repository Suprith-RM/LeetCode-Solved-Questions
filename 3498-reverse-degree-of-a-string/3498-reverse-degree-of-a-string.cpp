class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0, idx = 1;
        for(char ch: s){
            ans += (idx++) * (26-(ch-'a'));
        }
        return ans;
    }
};