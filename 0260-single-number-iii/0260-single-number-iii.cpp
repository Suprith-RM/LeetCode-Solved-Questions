class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xor_all = 0;
        for(int num: nums) xor_all ^= num;
        unsigned int rightMost = (xor_all & (xor_all - 1)) ^ xor_all; 
        int buck_1 = 0, buck_2 = 0;
        for(int num: nums){
            if((rightMost & num) != 0)
                buck_1 = (buck_1 ^ num);
            else
                buck_2 = (buck_2 ^ num);
        }
        return {buck_1, buck_2};
    }
};