class Solution {
    void slideover(vector<vector<int>>& img1, vector<vector<int>>& img2,
                   int& ans) {
        int n = img1.size();
        for (int i = -(n - 1); i < n; ++i) {
            for (int j = -(n - 1); j < n; ++j) {
                int overlap = 0;
                for (int l = 0; l < n; ++l) {
                    for (int m = 0; m < n; ++m) {
                        int p = l + i;
                        int q = m + j;
                        if (p >= 0 && p < n && q >= 0 && q < n &&
                            img1[l][m] == 1 && img2[p][q] == 1) {
                            overlap++;
                        }
                    }
                }
                ans = max(ans, overlap);
            }
        }
    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0;
        slideover(img1, img2, ans);
        return ans;
    }
};