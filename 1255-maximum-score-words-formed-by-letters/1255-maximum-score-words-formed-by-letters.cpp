class Solution {
    void generate_subsets(vector<string>& words, vector<vector<string>>& subsets, vector<string>& temp, int idx){
        if(idx >= words.size()){
            subsets.push_back(temp);
            return;
        }
        // include
        temp.push_back(words[idx]);
        generate_subsets(words, subsets, temp, idx+1);
        temp.pop_back();
        // exclusion
        generate_subsets(words, subsets, temp, idx+1);
    }
    bool valid(vector<string>& subset, vector<int> freq, vector<int>& score, int& scr){
        for(auto& word: subset){
            for(auto& letter: word){
                if(freq[letter-'a'] == 0){
                    return false;
                }
                freq[letter-'a']--;
                scr += score[letter-'a'];
            }
        }
        return true;
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<vector<string>> subsets;
        vector<string> temp;
        generate_subsets( words, subsets, temp, 0);
        vector<int> freq(26, 0);
        for(char letter: letters){
            freq[letter-'a']++;
        }
        int ans = 0;
        for(auto& subset: subsets){
            int scr = 0;
            if(valid(subset, freq, score, scr)){
                ans = max(ans, scr);
            }
        }
        return ans;
    }
};