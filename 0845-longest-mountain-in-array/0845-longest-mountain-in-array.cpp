class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0, i = 0, n = arr.size();
        while(i < n){
            int j = i;
            while(j < n-1 && arr[j] < arr[j+1]){
                j++;
            }
            if(j == i){
                i++;
                continue;
            }
            int peak = j;
            while(j < n-1 && arr[j] > arr[j+1]){
                j++;
            }
            if(j != peak) ans = max(ans, j - i + 1);
            i = j;
        }
        return ans;
    }
};