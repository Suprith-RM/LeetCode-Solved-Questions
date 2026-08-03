class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char ch: tasks){
            freq[ch-'A']++;
        }
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        for(int i = 0; i < 26; ++i){
            if(freq[i] != 0){
                pq.push(freq[i]);
            }
        }
        int time = 0;
        while(!pq.empty() || !q.empty()){
            while(!q.empty() && q.front().second <= time){
                if(q.front().first > 0) pq.push({q.front().first});
                q.pop(); 
            } 
            if (!pq.empty()) {
                int rem = pq.top() - 1;
                pq.pop();

                if (rem > 0)
                q.push({rem, time + n + 1});
            }
            time++;
        }
        return time;
    }
};