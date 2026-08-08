class Solution {
public:
    int minNumberOfFrogs(string s) {
        int arr[] = {0, 0, 0, 0, 0};
        //           c  r  o  a  k
        int active = 0, ans = 0;
        for(char ch: s){
            if(ch == 'c'){
                arr[0]++;
                active++;
            } else if(ch == 'r'){
                if(arr[0] == arr[1]) return -1;
                arr[1]++;
            } 
            else if(ch == 'o'){
                if(arr[1] == arr[2]) return -1;
                arr[2]++;
            } 
            else if(ch == 'a'){
                if(arr[2] == arr[3]) return -1;
                arr[3]++;
            } 
            else{
                if(arr[3] == arr[4]) return -1;
                arr[4]++;
                active--;
            }
            ans = max(ans, active);
        }
        for(int i = 1; i < 5; ++i){
            if(arr[i] != arr[i-1]) return -1; 
        }
        return ans;
    }
};