class Solution {
public:
    int maxPalindromes(string s, int k) {
        if (k == 1)
            return s.size();
        int n = s.size();
        vector<vector<int>> arr;
        for (int c = 0; c < n; c++) {
            int l = c, r = c;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k)
                    arr.push_back({l, r});
                l--;
                r++;
            }
            l = c;
            r = c + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k)
                    arr.push_back({l, r});
                l--;
                r++;
            }
        }
        sort(arr.begin(), arr.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });
        int cnt = 0, curr = -1;
        for (auto& intv : arr) {
            if (intv[0] > curr) {
                cnt++;
                curr = intv[1];
            }
        }
        return cnt;
    }
};