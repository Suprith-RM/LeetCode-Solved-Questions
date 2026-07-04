class Solution {
    int pairs(vector<int> &cnt, int &InternalPairs){
        int rem = 0;

        for (int x : cnt)
            rem += x;

        int mx = 0;
        for (int x : cnt)
            mx = max(mx, x);

        InternalPairs += min(rem / 2, rem - mx);

        return rem - 2 * min(rem / 2, rem - mx);
    }
public:
    int score(vector<string>& cards, char x) {
        vector<int> left(26, 0);
        vector<int> right(26, 0);
        int same = 0;
        for(string s: cards){
            if(s[0] == x && s[1] == x) same++;
            else if (s[0] == x) left[s[1]-'a']++;
            else if (s[1] == x) right[s[0]-'a']++;
        }
        int leftovers = 0;
        int internalPairs = 0;
        leftovers += pairs(left, internalPairs);
        leftovers += pairs(right, internalPairs);
        int ans = internalPairs;
        ans += min(same, leftovers);
        same -= min(same, leftovers);
        ans += min(same / 2, internalPairs);
        return ans;
    }
};