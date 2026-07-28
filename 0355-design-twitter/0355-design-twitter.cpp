class Twitter {
public:
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> newsFeed;
    int timer;
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        newsFeed[userId].push_back({timer, tweetId});
        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for(auto& pairTN: newsFeed[userId]){
            pq.push(pairTN);
        }
        for(const auto& it: followers[userId]){
            for(auto& pairTN: newsFeed[it]){
                pq.push(pairTN);
            }
        }
        vector<int> newsRes;
        while(!pq.empty() && newsRes.size() != 10){
            newsRes.push_back(pq.top().second);
            pq.pop();
        }
        return  newsRes;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */