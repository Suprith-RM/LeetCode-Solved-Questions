class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int ans = 0;
        int d_rows = 0;
        int prev = 0;
        int j = 0;
        while(j < reservedSeats.size()){
            int curr_row = reservedSeats[j][0];
            if(curr_row != prev){
                d_rows++;
                prev = curr_row;
            }
            bool p1 = true;
            bool p2 = true;
            bool p3 = true;
            while(j < reservedSeats.size() && reservedSeats[j][0]  == curr_row){
                int check = reservedSeats[j][1];
                if(check >=2 && check <= 5){
                    p1 = false;
                }
                if(check >= 4 && check <= 7){
                    p2 = false;
                }
                if(check >= 6 && check <= 9){
                    p3 = false;
                }
                j++; 
            }
            if(p1 || p3){
                if(p1 & p3)ans+=2;
                else ans+=1;
            }
            else if(p2){
                ans+=1;
            }

        }
        ans += (n - d_rows)*2;

        return ans;
    }
};