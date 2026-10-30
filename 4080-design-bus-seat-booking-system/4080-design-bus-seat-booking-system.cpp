class BusBooking {
public:
    vector<vector<int>> mp;
    int total_time, min_time;
    BusBooking(int n) {
        mp = vector<vector<int>>(n, vector<int>(4, 0));
        total_time = 0, min_time = 0;
    }

    void toggle(string seat) {
        int row = stoi(seat.substr(1)) - 1;
        int col = seat[0] - 'A';

        if (mp[row][col] == 0) {
            if (seat[0] == 'A' && mp[row][1] == 1) {
                total_time += 3;
                mp[row][col] = 3;
            } else if (seat[0] == 'D' && mp[row][2] == 1) {
                total_time += 3;
                mp[row][col] = 3;
            } else {
                mp[row][col] = 1;
                total_time++;
            }

            min_time++;
        } else {
            min_time--;
            total_time -= mp[row][col];
            mp[row][col] = 0;
        }
    }
    int getTotalTime() { return total_time; }

    int getMinTime() { return min_time; }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */