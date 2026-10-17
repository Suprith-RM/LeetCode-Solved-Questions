class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            int curr = 0, tmp = nums[i];
            while (tmp > 0) {
                curr += tmp % 10;
                tmp /= 10;
            }
            arr[i] = {curr, i};
        }
        sort(arr.begin(), arr.end(),
             [&nums](const pair<int, int>& a, const pair<int, int>& b) {
                 if (a.first == b.first) {
                     return nums[a.second] < nums[b.second];
                 }
                 return a.first < b.first;
             });
        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i].second == i) {
                continue;
            }

            int cycle_size = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycle_size++;
            }

            swaps += cycle_size - 1;
        }
        return swaps;
    }
};