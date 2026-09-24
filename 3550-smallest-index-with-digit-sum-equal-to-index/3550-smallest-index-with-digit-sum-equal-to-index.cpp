class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int idx = 0;
        for(int num: nums){
            int sum = 0;
            while(num > 0){
                sum += num % 10;
                num /= 10;
            }
            if(sum == idx)
                return idx;
            idx++;
        }
        return -1;
    }
};