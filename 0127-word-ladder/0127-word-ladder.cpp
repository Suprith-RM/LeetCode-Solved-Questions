class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool found = false;
        int n = wordList.size();
        unordered_set<string> st;
        for(int i = 0; i < n; ++i){
            string s = wordList[i];
            if(!found && s == endWord) found = true;
            st.insert(s);
        }
        if(!found) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            auto [word, dist] = q.front();
            q.pop();
            if(word == endWord) return dist;
            for(int i = 0, len = word.size(); i < len; ++i){
                string temp = word;
                for(int j = 0; j < 26; ++j){
                    temp[i] = 'a' + j;
                    if(st.find(temp) != st.end()){
                        q.push({temp, dist+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};