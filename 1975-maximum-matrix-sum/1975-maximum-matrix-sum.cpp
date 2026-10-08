class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), negs = 0, mini = INT_MAX;
        long long sum = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] < 0)
                    negs++;
                mini = min(mini, abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }
        if(negs % 2 == 0)
            return sum;
        sum -= (2*mini);
        return sum;
    }
};