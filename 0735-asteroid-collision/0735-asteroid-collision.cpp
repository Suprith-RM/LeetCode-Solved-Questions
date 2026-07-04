class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int asteroid: asteroids){
            if(asteroid < 0){
                while(!st.empty() && st.top() > 0 && st.top() < abs(asteroid)) st.pop();
                if(st.empty() || st.top() < 0) st.push(asteroid);
                else if(st.top() == abs(asteroid)) st.pop();
                else if(st.top() > abs(asteroid)) continue;
            }
            else{
                st.push(asteroid);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};