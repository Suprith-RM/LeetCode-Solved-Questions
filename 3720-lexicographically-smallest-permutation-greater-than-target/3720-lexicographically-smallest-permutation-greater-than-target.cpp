class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26);

        for (char c : s)
            freq[c - 'a']++;

        int i = 0;

        while (i < n && freq[target[i] - 'a']) {
            freq[target[i] - 'a']--;
            i++;
        }

        if (i < n) {
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (freq[c]) {
                    string ans = target.substr(0, i);
                    ans += char('a' + c);
                    freq[c]--;

                    for (int x = 0; x < 26; x++)
                        ans += string(freq[x], char('a' + x));

                    return ans;
                }
            }
        }

        i--;

        while (i >= 0) {
            freq[target[i] - 'a']++;

            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (freq[c]) {
                    string ans = target.substr(0, i);
                    ans += char('a' + c);
                    freq[c]--;

                    for (int x = 0; x < 26; x++)
                        ans += string(freq[x], char('a' + x));

                    return ans;
                }
            }

            i--;
        }

        return "";
    }
};