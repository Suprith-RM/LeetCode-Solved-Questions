class Solution {
    void merge(vector<pair<int, int>>& nums, int s, int mid, int e, vector<int>& ans){
        int i = s, j = mid + 1;
        vector<pair<int, int>> temp;
        int rightCount = 0;
        while(i <= mid && j <= e){
            if(nums[i].first <= nums[j].first){
                ans[nums[i].second] += rightCount;
                temp.push_back(nums[i++]);
            } else{
                rightCount++;
                temp.push_back(nums[j++]);
            }
        }
        while(i <= mid){
            ans[nums[i].second] += rightCount;
            temp.push_back(nums[i++]);
        }
        while(j <= e){
            temp.push_back(nums[j++]);
        }
        for(int i = s; i <= e; ++i){
            nums[i] = temp[i - s];
        }
    }
    void mergeSort(vector<pair<int, int>>& nums, int s, int e, vector<int>& ans){
        if(s >= e) return;
        int mid = s + (e - s) / 2;
        mergeSort(nums, s, mid, ans);
        mergeSort(nums, mid+1, e, ans);
        merge(nums, s, mid, e, ans);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> arr(nums.size());
        for(int i = 0, len = nums.size(); i < len; ++i){
            arr[i] = make_pair(nums[i], i);
        }
        vector<int> ans(nums.size());
        mergeSort(arr, 0, nums.size()-1, ans);
        return ans;
    }
};