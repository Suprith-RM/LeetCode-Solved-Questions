class Solution {
    void helper(int n, int k, int idx, vector<int>& temp, vector<vector<int>>& res){
        if(temp.size() == k){
            res.push_back(temp);
            return;
        }
        for(int i = idx; i <= n; ++i){
            temp.push_back(i);
            helper(n, k, i+1, temp, res);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp; 
        helper(n, k, 1, temp, res);
        return res;
    }
};