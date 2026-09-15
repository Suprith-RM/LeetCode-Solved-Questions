class Solution {
public:
    string sortVowels(string s) {
        vector<pair<char, pair<int, int>>> freq = {
            {'a', {0, 0}},
            {'e', {0, 0}},
            {'i', {0, 0}},
            {'o', {0, 0}},
            {'u', {0, 0}},
        };
        int n = s.size();
        for(int i = n-1; i >= 0; --i){
            if(s[i] == 'a'){
                freq[0].second.first++;
                freq[0].second.second= i;
            }
            else if(s[i] == 'e'){
                freq[1].second.first++;
                freq[1].second.second= i;
            }
            else if(s[i] == 'i'){
                freq[2].second.first++;
                freq[2].second.second= i;
            }
            else if(s[i] == 'o'){
                freq[3].second.first++;
                freq[3].second.second= i;
            }
            else if(s[i] == 'u'){
                freq[4].second.first++;
                freq[4].second.second= i;
            }
        }
        sort(freq.begin(), freq.end(), [](pair<char,pair<int,int>>& a, pair<char, pair<int,int>>& b){
            if(a.second.first == b.second.first)
                return a.second.second < b.second.second;
            return a.second.first > b.second.first;
        });
        int j = 0;
        for(int i = 0; i < n; ++i){
            if(j < 5 && freq[j].second.first == 0) j++;
            if(j < 5 && (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')){
                freq[j].second.first--;
                s[i] = freq[j].first;
            }
        }
        return s;
    }
};