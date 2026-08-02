class Solution {
    void check_subsets(vector<string>& words, vector<int>& score, vector<int>& freq, int& scr, int idx, int currScore){
        if(idx >= words.size()){
            scr = max(currScore, scr);
            return;
        }
        check_subsets(words, score, freq, scr, idx + 1, currScore);

        int wordScore = 0;
        bool possible = true;
        for(char letter: words[idx]){
            if(freq[letter-'a'] == 0) 
                possible = false;
            freq[letter-'a']--;
            wordScore += score[letter-'a'];
        }
        if(possible) 
            check_subsets(words, score, freq, scr, idx + 1, currScore + wordScore);
        for (char c : words[idx]) {
            freq[c - 'a']++;
        }
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
        for(char letter: letters){
            freq[letter-'a']++;
        }
        int scr = 0;
        check_subsets(words, score, freq, scr, 0, 0);
        return scr;
    }
};