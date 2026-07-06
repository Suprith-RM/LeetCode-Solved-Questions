class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intv) {
        int n = intv.size();
        sort(intv.begin(), intv.end(), [](vector<int>& a, vector<int>& b){
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        int right = intv[n-1][1], left = intv[n-1][0];
        int cnt = 0;
        for(int i = n-2; i >= 0; --i){
            if(intv[i][0] >= left && intv[i][1] <= right){
                cnt++;
            }
            else{
                left = intv[i][0];
                right = intv[i][1];
            }
        }
        return n - cnt;
    }
};