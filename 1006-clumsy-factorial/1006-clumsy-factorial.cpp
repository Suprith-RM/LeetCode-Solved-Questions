class Solution {
public:
    int clumsy(int n) {
        if(n <= 2) 
            return n;
        int ans = (n * (n-1)) / (n-2);
        n-=3;
        while(n > 0){
            ans += n;
            n--;
            if(n > 2){
                ans -= (n *( n - 1)) / (n-2);
                n-=3;
            }
            else {
                ans -= n;
                break;
            }
        }
        return ans;
    }
};