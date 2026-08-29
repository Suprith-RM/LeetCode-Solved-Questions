class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for(int i = 0; i < n; ++i){
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        int i = 0;
        while(i < n){
            int j = i;
            while(j < n-1 && arr[j+1].first - arr[j].first <= limit){
                j++;
            }

            vector<int> indices;

            for(int k = i; k <= j; ++k){
                indices.push_back(arr[k].second);
            }
            sort(indices.begin(), indices.end());
            for(int k = 0; k < indices.size(); ++k){
                nums[indices[k]] = arr[i + k].first;
            }
            i = j + 1;
        }
        return nums;
    }
};