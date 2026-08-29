class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                pq.push({freq[i], 'a' + i});
        }

        string ans;
        while (pq.size() >= 2) {
            auto [f1, c1] = pq.top();
            pq.pop();

            auto [f2, c2] = pq.top();
            pq.pop();

            ans += c1;
            ans += c2;

            f1--;
            f2--;

            if (f1 > 0)
                pq.push({f1, c1});

            if (f2 > 0)
                pq.push({f2, c2});
        }
        if (!pq.empty()) {
            auto [f, c] = pq.top();

            if (f > 1)
                return "";

            ans += c;
        }

        return ans;
    }
};