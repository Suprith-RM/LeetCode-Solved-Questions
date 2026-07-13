class Solution {
public:
   void helper(vector<int>& candidates, int& target, int idx, int temp,vector<int> &t, vector<vector<int>>& ans) {
    if (temp == target) {
        ans.push_back(t);
        return;
    }
    if(temp > target || idx >= candidates.size()) return;


    for (int s = idx; s < candidates.size(); s++) {
        if (temp < target) {
            t.push_back(candidates[s]);
            helper(candidates,target,s,temp + candidates[s],t,ans);
            t.pop_back();
        }
    }


}




vector<vector<int>> combinationSum(vector<int>& candidates, int &target) {
    int idx = 0;
    int temp = 0;
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> t;
    helper(candidates, target, idx,temp,t,ans);
    return ans;
}
};