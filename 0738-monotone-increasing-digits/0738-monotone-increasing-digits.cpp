class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int last_idx = s.size();
        int i = s.size()-1;
        while(i > 0){
            if(s[i] < s[i-1]){
                i--;
                while(i > 0 && s[i] == s[i-1]) i--;
                last_idx = i;
            }
            else i--;
        }
        if (last_idx == s.size())
            return n;

        s[last_idx]--;

        for (int j = last_idx + 1; j < s.size(); j++) {
            s[j] = '9';
        }

        return stoi(s);
    }
};