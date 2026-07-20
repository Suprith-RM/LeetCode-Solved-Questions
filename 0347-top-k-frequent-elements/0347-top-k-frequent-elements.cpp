class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int num: nums){
            mp[num]++;
        }
        for(const auto [key, val]: mp){
            if(minHeap.size() < k) minHeap.push({val, key});
            else if(minHeap.top().first < val){
                minHeap.pop();
                minHeap.push({val, key});
            }
        }
        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};