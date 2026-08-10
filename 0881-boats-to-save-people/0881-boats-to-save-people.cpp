class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size(), i = 0, j = n-1, cnt = 0;
        while(i <= j){
            if(i != j && people[i] + people[j] <= limit){
                cnt++;
                people[i] = 0;
                people[j] = 0;
                i++; 
                j--;
                continue;
            }
            else j--;
        }
        sort(people.begin(), people.end());
        i = 0;
        for(i = cnt * 2; i < n; i+=2){
            if(i < n-1 && people[i] + people[i+1] <= limit) cnt++;
            else break;
        }
        cnt += (n-i);
        return cnt;
    }
};