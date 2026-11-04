class Solution {
public:
    string simplifyPath(string s) {
        stack<string> st;
        int n = s.size(), i = 0;

        while(i < n) {
            string x = "";
            while(i < n && s[i] == '/') i++;
            while(i < n && s[i] != '/')
                x += s[i++];
            if(x == "" || x == ".")
                continue;
            if(x == "..") {
                if(!st.empty()) st.pop();
            }
            else {
                st.push(x);
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans.empty() ? "/" : ans;
    }
};