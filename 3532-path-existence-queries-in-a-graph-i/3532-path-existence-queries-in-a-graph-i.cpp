class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int numOfPaths = 1;
        vector<int> paths;
        for(int i = 0; i < n; ++i){
            if(i == 0 || nums[i] - nums[i-1] <= maxDiff){
                paths.push_back(numOfPaths);
            }
            else{
                numOfPaths++;
                paths.push_back(numOfPaths);
            }
        }
        vector<bool> res;
        for(auto it: queries){
            res.push_back(paths[it[0]] == paths[it[1]]);
        }
        return res;
    }
};