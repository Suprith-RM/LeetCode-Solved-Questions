class Solution {
public:
    int minChanges(string s) {
        int n = s.size(), prev = 0, cnt = 0, i = 0;
        while(i < n){
            char curr = s[i];
            int curr_cnt = 0;
            while(i < n && s[i] == curr){
                i++;
                curr_cnt++;
            }
            if(curr_cnt % 2 == 0){
                if(prev == 1){
                    cnt++;
                }
                else
                    prev = 0;
            }
            else{
                if(prev == 0){
                    cnt++;
                    prev = 1;
                }
                else 
                    prev = 0;
            }
        }
        return cnt;
    }
};