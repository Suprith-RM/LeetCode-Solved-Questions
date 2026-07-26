class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> ans;
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            ++i;
        }
        int left = newInterval[0], right = newInterval[1];
        while (i < n && intervals[i][0] <= right){
            left = min(left, intervals[i][0]);
            right = max(right, intervals[i][1]);
            i++;
        }
        ans.push_back({left, right});
        for(;i < n; ++i){
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};