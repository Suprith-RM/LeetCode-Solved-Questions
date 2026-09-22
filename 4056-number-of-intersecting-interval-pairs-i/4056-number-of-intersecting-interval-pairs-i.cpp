class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0, n = intervals.size();
        for(int i = 0; i < n-1; ++i){
            int end = intervals[i][1];
            int j = i + 1;
            while(j < n && intervals[j][0] <= end){
                ans++;
                j++;
            }
        }
        return ans;
    }
};