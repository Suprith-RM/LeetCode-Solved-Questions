class Solution {
public:
    int mySqrt(int x) {
        int l = 0, h = x;
        while(l <= h){
            long long mid = 1LL*l + (h - l)/2;
            if(mid * mid <= x && (mid + 1)*(mid+1) > x){
                return mid;
            }
            if(mid * mid > x){
                h = mid -1;
            }
            else 
                l = mid + 1;
        }
        return -1;
    }
};