class Solution {

public:
    bool helper(string& s, string& p, int idx_s, int idx_p) {
        if(idx_s < 0 && idx_p >= 0){
            while(idx_p >= 0 && p[idx_p] == '*') idx_p-=2;
            if(idx_p < 0) return true;
            return false;
        }
        if (idx_p < 0 && idx_s > 0)
            return false;
        if (idx_s < 0 && idx_p < 0) {
            return true;
        }
        if (idx_p >= 0) {
            if (p[idx_p] == '*') {
                if (p[idx_p - 1] == '.') {
                    if (helper(s, p, idx_s - 1, idx_p))
                        return true;
                    if (helper(s, p, idx_s, idx_p - 2))
                        return true;
                } else if (p[idx_p - 1] == '*') {
                    if (helper(s, p, idx_s, idx_p - 1))
                        return true;
                } else {
                    if (s[idx_s] == p[idx_p - 1]) {
                        if (helper(s, p, idx_s - 1, idx_p))
                            return true;
                        if (helper(s, p, idx_s, idx_p - 2))
                            return true;
                    } else {
                        if (helper(s, p, idx_s, idx_p - 2))
                            return true;
                    }
                }
            } else if (p[idx_p] == '.') {
                if (helper(s, p, idx_s - 1, idx_p - 1))
                    return true;
            } else {
                if (s[idx_s] == p[idx_p])
                    if (helper(s, p, idx_s - 1, idx_p - 1))
                        return true;
                    else
                        return false;
            }
        }
        return false;
    }
    bool isMatch(string s, string p) {
        return helper(s, p, s.size() - 1, p.size() - 1);
    }
};