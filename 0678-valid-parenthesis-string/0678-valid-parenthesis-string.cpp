class Solution {
public:
    bool checkValidString(string s) {
    int bal = 0;
    for (char c : s) {
        if (c == '(' || c == '*') bal++;
        else bal--;

        if (bal < 0) return false;
    }
    bal = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == ')' || s[i] == '*') bal++;
        else bal--;

        if (bal < 0) return false;
    }

    return true;
}
};