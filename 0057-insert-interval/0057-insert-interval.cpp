class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int left = intervals[0][0], right = intervals[0][1];
        for(auto& it: intervals){
            if(it[0] <= right){
                left = min(left, it[0]);
                right = max(right, it[1]);
            }
            else {
                ans.push_back({left, right});
                left = it[0];
                right = it[1];
            }
        }
        ans.push_back({left, right});
        return ans;
    }
};