class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size()-1, score = 0, ans = 0;
        while(i <= j){
            if(score == 0 && tokens[i] > power) return ans;
            else if(score > 0 && tokens[i] > power){
                score--;
                power += tokens[j--];
            }
            while (i <= j && power >= tokens[i]){
                score++;
                power -= tokens[i];
                ans = max(ans, score);
                i++;
            }
        }
        return ans;
    }
};