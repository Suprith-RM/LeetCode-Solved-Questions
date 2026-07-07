class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int> st;
        stack<int> temp;
        for(int i = n-1; i >= 0; --i){
            st.push(num[i] - '0');
        }
        while(!st.empty()){
            
            if(!st.empty()){
                temp.push(st.top());
                st.pop();
            }
            while (k > 0 && !temp.empty() && !st.empty() && st.top() < temp.top()){
                temp.pop();
                k--;
            }

            while(temp.empty() && !st.empty() && st.top() == 0) st.pop();
        }
        while(k > 0 && !temp.empty()){
            k--;
            temp.pop(); 
        } 
        string ans;
        while(!temp.empty()){
            ans.push_back(temp.top() + '0');
            temp.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans == "" ? "0" : ans;
    }
};