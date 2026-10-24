
class Solution {
    vector<int> pref = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int convert(string& s) {
            int month = stoi(s.substr(0, 2));
            int day = stoi(s.substr(3, 2));
            return pref[month - 1] + day;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int a1 = convert(arriveAlice);
        int a2 = convert(leaveAlice);
        int b1 = convert(arriveBob);
        int b2 = convert(leaveBob);
        return max(0, min(a2, b2) - max(a1, b1) + 1);
    }
};
