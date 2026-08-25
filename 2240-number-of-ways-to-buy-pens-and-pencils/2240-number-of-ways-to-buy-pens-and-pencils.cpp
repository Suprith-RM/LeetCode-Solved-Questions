class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int numPens = (total / cost1);
        long long ans = 0;
        for(int i = 0; i <= numPens; ++i){
            int rem = total - (cost1 * i);
            int numPencils = (rem / cost2);
            ans += (numPencils+1);
        }
        return ans;
    }
};