class Solution {
public:
    bool threeFibonacciSum(int n) {
        int a = 0, b = 1, c = 1;
        while(a + b + c <= n){
            if(a + b + c == 1LL*n){
                return true;
            }
            int temp = b;
            a = b;
            b = c;
            c = a + c;
        }
        return false;
    }
};