class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> sttr;
        string temp = "";
        int digit = 0;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                digit = digit * 10 + (c - '0');
            }
            else if (c == '[') {
                num.push(digit);
                sttr.push(temp);

                digit = 0;
                temp = "";
            }
            else if (c == ']') {
                int k = num.top();
                num.pop();
                string prev = sttr.top();
                sttr.pop();
                string repeated = "";
                for (int i = 0; i < k; i++) {
                    repeated += temp;
                }
                temp = prev + repeated;
            }
            else {
                temp += c;
            }
        }

        return temp;
    }
};