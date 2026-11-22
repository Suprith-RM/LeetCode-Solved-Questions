class Solution {
public:
    int minRange(int a, int b, int c) {
        int maxi = max(a, max(b, c)), mini = min(a, min(b, c)),  sum = a + b + c;
        if(sum - maxi < maxi){
            return sum - maxi - mini;
        }
        return maxi - mini;
    }
};