class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int num) {
        int i = 0, cnt = 0, n = arr.size();
        if(n == 1){
            if(num == 0 || (num == 1 && arr[0] == 0))
                return true;
            else return false;
        } 
        while(i < n){
            if(arr[i] == 1) i++;
            if(i == 0){
                if(arr[i+1] == 0){
                    cnt++;
                    i+=2;
                }
                else i++;
            }
            
            else if(i == n-1){
                if(arr[i-1] == 0){
                    cnt++;
                    i+=2;
                }
                else i++;
            }
            else if(arr[i-1] != 1 && arr[i+1] != 1){
                cnt++;
                i+=2;
            }
            
            else i++;
        }
        return cnt >= num;
    }
};