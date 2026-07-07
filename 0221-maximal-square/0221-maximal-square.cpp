class Solution {
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i <= n; ++i){
            while(!st.empty() && ( i == n || heights[st.top()] > heights[i])){
                int h = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                int len = min(h, width);
                ans = max(ans, (len * len));
            }
            st.push(i);
        }
        return ans;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> histo(m);
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(matrix[i][j] == '1') histo[j]++;
                else histo[j] = 0;
            }
            ans = max(ans, largestRectangleArea(histo));
        }
        return ans;
    }
};