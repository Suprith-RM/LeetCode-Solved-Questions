class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), mini = 0, maxi = 0;
        if(n <= 1)
            return 0;
        bool sorted = true;
        for(int i = 1; i < n; ++i){
            if(s[i] < s[i-1]){
                sorted = false;
            }
            if(s[i] < s[mini])
                mini = i;
            if(s[i] >= s[maxi])
                maxi = i;
        }
        if(!sorted && n == 2)
            return -1;
        if(sorted)
            return 0;
        if(mini == 0 || maxi == n-1)
            return 1;
        if(mini == n-1 && maxi == 0)
            return 3;
        return 2;

    }
};