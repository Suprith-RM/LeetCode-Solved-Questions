class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cood) {
        int n = cood.size();
        for(int i = 2; i < n; ++i){
            if((cood[i][0] - cood[0][0]) * (cood[1][1] - cood[0][1])  != (cood[i][1] - cood[0][1]) * (cood[1][0] - cood[0][0])) return false;
        }
        return true;
    }
};