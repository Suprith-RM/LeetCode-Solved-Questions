class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = *min_element(nums1.begin(), nums1.end());
        if(mini % 2 == 0){
            for(int num: nums1){
                if(num % 2) return false;
            }
        }
        return true;
    }
};