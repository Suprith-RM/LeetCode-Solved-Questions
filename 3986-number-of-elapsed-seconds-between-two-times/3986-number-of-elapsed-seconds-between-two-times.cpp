class Solution {
public:
    int secondsBetweenTimes(string st, string et) {
        int s_hour = (st[0]-'0') * 10 + (st[1]-'0');
        int e_hour = (et[0]-'0') * 10 + (et[1]-'0');
        int s_min = (st[3]-'0') * 10 + (st[4]-'0');
        int e_min = (et[3]-'0') * 10 + (et[4]-'0');
        int s_sec = (st[6]-'0') * 10 + (st[7]-'0');
        int e_sec = (et[6]-'0') * 10 + (et[7]-'0');
        return (e_hour - s_hour) * 3600 + (e_min - s_min) * 60 + (e_sec - s_sec);
    }
};