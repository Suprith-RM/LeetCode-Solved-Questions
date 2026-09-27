class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long ss = 0, st = 0;
        int n = source.size();
        for (int i = 0; i < n; ++i) {
            ss += source[i];
            st += target[i];
        }
        return ss == st;
    }
};