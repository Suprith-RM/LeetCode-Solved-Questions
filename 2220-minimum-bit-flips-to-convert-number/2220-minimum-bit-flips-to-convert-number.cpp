class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xori = (start ^ goal);
        int cnt = 0;
        while(xori){
            if((xori & 1) == 1) cnt++;
            xori >>= 1;
        }
        return cnt;
    }
};