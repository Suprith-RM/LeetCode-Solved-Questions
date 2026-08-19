class Solution {
    void counter(int& cnt, int idx, int pos, int n){
        if(pos == n){
            cnt++;
            return;
        }
        for(int i = idx; i < 5; ++i){
            counter(cnt, i, pos + 1, n);
        }
    }
public:
    int countVowelStrings(int n) {
        vector<int> arr(n);
        int cnt = 0;
        counter(cnt, 0, 0, n);
        return cnt;
    }
};