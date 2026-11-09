class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        set<int> st;
        for(int i = 0; i < k; ++i){
            st.insert(i);
        }
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        vector<int> cnt(k, 0);
        for(int i = 0; i < n; ++i){
            while(!pq.empty() && pq.top().first <= arrival[i]){
                st.insert(pq.top().second);
                pq.pop();
            }
            if (st.empty())
                continue;
            int need = i % k;
            auto it = st.lower_bound(need);
            if (it == st.end())
                it = st.begin();
            int server = *it;
            st.erase(it);
            cnt[server]++;
            pq.push({arrival[i] + load[i], server});
        }

        int maxi = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;

        for(int i = 0; i < k; ++i){
            if(cnt[i] == maxi)
                ans.push_back(i);
        }

        return ans;

    }
};