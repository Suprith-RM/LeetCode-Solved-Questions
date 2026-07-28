class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int x = 1, left = 0, right = n-1, up = 0, down = n-1;
        vector<vector<int>> arr(n, vector<int>(n));
        while(left <= right && up <= down){
            for(int i = left; i <= right; ++i){
                arr[up][i] = x;
                x++;
            }
            up++;
            for(int i = up; i <= down; ++i){
                arr[i][right] = x;
                x++;
            }
            right--;
            for(int i = right; i >= left; --i){
                arr[down][i] = x;
                x++;
            }
            down--;
            for(int i = down; i >= up; --i){
                arr[i][left] = x;
                x++;
            }
            left++;
        }
        return arr;
    }
};