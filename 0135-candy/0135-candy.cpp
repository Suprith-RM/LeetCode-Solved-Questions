class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> arr(n, 1);
        int i = n-2;
        while(i >= 0) {
            int cnt = 2;
            while(i >= 0 && ratings[i] > ratings[i+1]){
                arr[i] = cnt;
                cnt++, i--;
            }
            if(i >= 0) arr[i] = 1;
            i--;
        } 
        int sum = arr[0];
        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i-1])arr[i] = max(arr[i-1] + 1, arr[i]);
            sum += arr[i];
        }
        return sum;
    }
};