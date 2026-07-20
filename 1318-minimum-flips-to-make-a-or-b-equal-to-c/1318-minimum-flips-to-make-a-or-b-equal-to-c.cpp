class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        while(a > 0 || b > 0 || c > 0){
            int tempA = (a & 1);
            int tempB = (b & 1);
            int tempC = (c & 1);
            if((tempA | tempB) != tempC){
                cnt++;
                if(tempC == 0 && tempA == 1 && tempB == 1) cnt++;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return cnt;
    }
};