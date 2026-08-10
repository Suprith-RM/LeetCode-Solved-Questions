class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size(), i = 0, j = n-1, cnt = 0;
        while(i <= j){
            if(people[i] + people[j] <= limit){
                i++;
            }
            j--;
            cnt++;
        }
        return cnt;
    }
};