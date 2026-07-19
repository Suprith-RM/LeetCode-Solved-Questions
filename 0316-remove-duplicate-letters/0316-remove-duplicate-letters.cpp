class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> isremaining(26, 0), isformed(26, 0);
        for(char ch: s){
            isremaining[ch-'a']++;
        }
        stack<char> st;
        for(char ch: s){
            isremaining[ch-'a']--; 
            if(isformed[ch-'a'] == 0){
                while(!st.empty() && st.top() > ch && isremaining[st.top()-'a'] > 0){
                    isformed[st.top()-'a']--;
                    st.pop();
                }
                st.push(ch);
                isformed[ch-'a']++;
            } 
        }   
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};