class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int dx = abs(homePos[1] - startPos[1]); 
        int dy = abs(homePos[0] - startPos[0]); 
        int m, n;
        if(homePos[1] >= startPos[1]) m = 1;
        else m = -1;
        if(homePos[0] >= startPos[0]) n = 1;
        else n = -1;
        int ans = 0;
        for(int i = 1; i <= dx; i++){
            ans += colCosts[startPos[1] + (i * m)];
        }
        for(int i = 1; i <= dy; i++){
            ans += rowCosts[startPos[0] + (i * n)];
        }
        return ans;
    }
};