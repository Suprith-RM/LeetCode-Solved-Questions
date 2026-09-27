class Solution {
    string reverser(string& s, int& idx) {
        string x = "";

        while (idx < s.size() && s[idx] != ')') {
            if (s[idx] == '(') {
                idx++;
                string temp = reverser(s, idx);
                reverse(temp.begin(), temp.end());
                x += temp;
            }
            else {
                x += s[idx++];
            }
        }

        if (idx < s.size())
            idx++;

        return x;
    }

public:
    string reverseParentheses(string s) {
        int idx = 0;
        return reverser(s, idx);
    }
};