class Solution {
public:
    bool sumGame(string num) {
        int leftHalf = 0, rightHalf = 0, lspaces = 0, rspaces = 0, n = num.size();
        for(int i = 0; i < n; ++i){
                if(i < n / 2){
                    if(num[i] == '?'){
                        lspaces++;
                           
                    }
                    else leftHalf += num[i] - '0';
            }
            else{
                if(num[i] == '?'){
                        rspaces++; 
                }
                else rightHalf += num[i] - '0';
            }
        }
        int dif = abs(leftHalf - rightHalf);
        int moves = abs(rspaces - lspaces);
        if(dif == 0 && moves % 2 != 0) return true;
        if((leftHalf > rightHalf && lspaces > rspaces) || (rightHalf > leftHalf && rspaces >= lspaces)){
            int secDiff = (dif + (ceil(moves/2) * 9));
            if(moves/2 * 9 >= secDiff) return false;
        }
        else{
            int secDiff = dif - (ceil(moves/2.0) * 9);
            if(floor(moves/2) * 9 >= dif && secDiff >= 0) return false;
        }
        return true;
    }
};