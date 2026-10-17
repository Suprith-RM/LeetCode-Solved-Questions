class Solution {
    bool valid(vector<int>& nums, int mid, long long& left, long long k) {
        long long need = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > mid) {
                need += nums[i] - mid;
            }
            if (need > k)
                return false;
        }
        left = k - need;
        return true;
    }
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        for (int i = 0; i < n; ++i) {
            nums1[i] = abs(nums1[i] - nums2[i]);
        }
        sort(nums1.rbegin(), nums1.rend());
        long long k = 1LL * k1 + k2;
        long long left = 0;
        int s = 0, e = nums1[0];
        long long total = 0;
        for (int x : nums1) total += x;
        if (total <= k) return 0;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (valid(nums1, mid, left, k)) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        valid(nums1, s, left, k);
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int x = min(nums1[i], s);
            ans += 1LL * x * x;
        }
        int i = 0;
        while (left > 0 && i < n) {
            if (nums1[i] >= s && s > 0) {
                ans -= 1LL * s * s;
                ans += 1LL * (s - 1) * (s - 1);
                --left;
            }
            ++i;
        }
        return ans;
    }
};