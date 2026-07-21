class Solution {
    bool valid1(vector<int>& arr, int i){
        if(i % 2 == 0 && arr[i] <= arr[i+1] || i % 2 != 0 && arr[i] >= arr[i+1]){
            return false;
        }
        return true;
    }
    bool valid2(vector<int>& arr, int i){
        if(i % 2 == 0 && arr[i] >= arr[i+1] || i % 2 != 0 && arr[i] <= arr[i+1]){
            return false;
        }
        return true;
    }
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int i = 0, j = 0, n = arr.size(), ans = 1;
        for(int k = 0; k < n-1; ++k){
            if(!valid1(arr, k)) i = k + 1;
            if(!valid2(arr, k)) j = k + 1;
            ans = max(ans, max(k - i + 2, k - j + 2));
        }
        return ans;   
    }
};