class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> ans(n);
        for(int i = 0; i < n; ++i){
            ans[i] = {arr[i], i};
        }
        int curr_rank = 1;
        sort(ans.begin(), ans.end());
        for(int i = 0; i < n; ++i){
            if(i !=0 && ans[i].first != ans[i-1].first){
                curr_rank++;
            }
            arr[ans[i].second] = curr_rank;
        }
        return arr;
    }
};