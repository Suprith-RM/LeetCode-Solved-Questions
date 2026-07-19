class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) { 
        int pos = 0, n = nums.size();
        for(int i = 0; i < n; ++i)
            if(nums[i] >= 0) pos++;
        if (pos == 0) return nums;
        k = k % pos;
        if (k == 0) return nums;
        int idx = 0;
        while(k){
            if(nums[idx] >= 0) k--;
            if(k > 0) idx++;
        }
        int i = 0, j = idx;
         while(i < j){
            while(nums[i] < 0 && i < j) i++;
            while(nums[j] < 0 && i < j) j--;
            swap(nums[i], nums[j]);
            i++, j--;
        }
        i = idx + 1, j = n-1;
         while(i < j){
            while(nums[i] < 0 && i < j) i++;
            while(nums[j] < 0 && i < j) j--;
            swap(nums[i], nums[j]);
            i++, j--;
        }
        i = 0, j = n-1;
        while(i < j){
            while(nums[i] < 0 && i < j) i++;
            while(nums[j] < 0 && i < j) j--;
            swap(nums[i], nums[j]);
            i++, j--;
        }
        return nums;
    }
};