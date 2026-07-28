class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, e = nums.size()-1;
        while(l <= e){
            int m = l + (e-l)/2;
            cout << l << " " << m << " " << e << endl;
            if(nums[m] == target) return true;
            if(nums[m] == nums[l]){
                l++;
                continue;
            } if(nums[m] == nums[e]){
                e--;
                continue;
            }
            if(nums[m] >= nums[l]){
                if(target >= nums[l] && target <= nums[m]){
                    e = m-1;
                }
                else{
                    l = m + 1;
                }
            }
            else{
                if(target <= nums[e] && target >= nums[m]){
                    l = m + 1;
                }
                else {
                    e = m -1;
                }
            }
        } 
        return false;
    }
};