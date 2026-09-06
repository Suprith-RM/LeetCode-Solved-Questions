class Solution {
    void unionBR(int a, int b, vector<int>& rank, vector<int>& par) {
        int parA = findPar(a, par);
        int parB = findPar(b, par);

        if (parA == parB)
            return;

        if (rank[parA] >= rank[parB]) {
            par[parB] = parA;

            if (rank[parA] == rank[parB])
                rank[parA]++;
        }
        else {
            par[parA] = parB;
        }
    }
    int findPar(int x, vector<int>& par) {
        if (par[x] == x)
            return x;

        return par[x] = findPar(par[x], par);
    }
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> par(26);
        vector<int> rank(26, 0);
        for (int i = 0; i < 26; i++) {
            par[i] = i;
        }
        for (string& s : equations) {
            if (s[1] == '=') {

                int a = s[0] - 'a';
                int b = s[3] - 'a';

                unionBR(a, b, rank, par);
            }
        }
        for (string& s : equations) {
            if (s[1] == '!') {
                int a = s[0] - 'a';
                int b = s[3] - 'a';
                if (findPar(a, par) == findPar(b, par))
                    return false;
            }
        }

        return true;
    }
};