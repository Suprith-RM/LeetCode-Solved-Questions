class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, n = arr.size(), cnt = 0;
        for(int i = 0; i < n; ++i){
            sum += arr[i];
            if(i + 1 >= k){
                if(sum / k >= threshold) cnt++;
                sum -= arr[i - k + 1];
            }
        }
        return cnt;
    }
};