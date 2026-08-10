class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& health, string directions) {
        int n = positions.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });
        stack<int> st;
        for(int idx: order){
            if(directions[idx] == 'R') st.push(idx);
            else{
                while(!st.empty() && health[idx] > 0){
                    int right = st.top();
                    if(health[right] > health[idx]){
                        health[right]--;
                        health[idx] = 0;
                    }
                    else if (health[right] == health[idx]){
                        health[right] = 0;
                        health[idx] = 0;
                        st.pop();
                    }
                    else{
                        health[right] = 0;
                        health[idx]--;
                        st.pop();
                    }
                }
            }
        }
        vector<int> ans;
        for(int idx = 0; idx < n; ++idx){
            if (health[idx] > 0) ans.push_back(health[idx]);
        }
        return ans;
    }
};