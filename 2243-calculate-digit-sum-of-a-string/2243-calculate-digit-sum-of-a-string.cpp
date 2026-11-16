class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string temp;
            int i = 0, n = s.size();
            while(i < n){
                int digits = 0, lt = i + k;
                while(i < n && i < lt){
                    digits += (s[i++] - '0');
                }
                temp += to_string(digits);
            }
            s = temp;
        }
        return s;
    }
};