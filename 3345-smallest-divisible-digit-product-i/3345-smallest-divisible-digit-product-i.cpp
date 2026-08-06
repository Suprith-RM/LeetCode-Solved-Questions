class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int num = n; num <= 100; ++num){
            int temp = num, prod = 1;
            while(temp > 0){
                prod *= temp % 10;
                temp /= 10;
                if(prod == 0 || prod % t == 0) return num;
            }
        }
        return 0;
    }
};