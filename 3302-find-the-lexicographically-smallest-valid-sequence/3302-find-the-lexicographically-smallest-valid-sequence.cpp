class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size(), j = m-1;
        vector<int> suffMatch(n);
        for(int i = n-1; i >= 0; --i){
            if(j >= 0 && word1[i] == word2[j]){
                j--;
            }
            suffMatch[i] = m - j ;
        }
        j = 0;
        bool mismatch = false;
        vector<int> ans;
        for(int i = 0; i < n && j < m; ++i){
            if(word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            } 
            else{
                if(i == n-1 && j < m-1){
                    return {};
                } 
                else if(i == n-1 && j == m-1){
                    ans.push_back(i);
                    return ans;
                }
                if (suffMatch[i + 1] >= m - j){
                    ans.push_back(i);
                    j++;
                    i++;
                    while(i < n && j < m){
                        if(word1[i] == word2[j]){
                            ans.push_back(i);
                            j++;
                        }
                        i++;
                    }
                } 
            }
        }
        return ans;
    }
};