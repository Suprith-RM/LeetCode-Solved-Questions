class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int longestGreenSignal = *max_element(lights.begin(), lights.end()), penalty = 0;
        for(int arrival: arrivalTime){
            int r = arrival % period;
            if(r >= longestGreenSignal)
                penalty = max(penalty, (period - r));
        }
        return penalty;
    }
};