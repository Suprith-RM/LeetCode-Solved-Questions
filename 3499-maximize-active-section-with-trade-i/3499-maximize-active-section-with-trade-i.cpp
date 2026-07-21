class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s = '1' + s + '1';
        int n = s.size();
        vector<pair<char, int>> rle;
        for(char ch: s){
            if(rle.empty() || rle.back().first != ch){
                rle.push_back({ch, 1});
            } else{
                rle.back().second++;
            }
        }
        int max_len = INT_MIN;
        for(int i = 1, len = rle.size(); i < len - 1; ++i){
            if(rle[i-1].first == '0' && rle[i+1].first == '0'){
                max_len = max(max_len, (rle[i-1].second + rle[i+1].second));
            }
        }
        int ans = max_len;
        if(ans == INT_MIN) ans = 0;
        for(auto [ch, cnt]: rle){
            if(ch == '1') ans += cnt;
        }
        return (ans - 2);    
    }
};