class Twitter {
public:
    int timer;
    unordered_map<int,unordered_set<int>> followers;
    unordered_map<int,vector<pair<int,int>>> tweets;
    Twitter() {
        this->timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer,tweetId});
        followers[userId].insert(userId);
        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        for(auto &v : followers[userId])
        {
            for(auto &p : tweets[v])
            {
                pq.push(p);
            }
        }
        while(pq.size() > 10)
        {
            pq.pop();
        }
        vector<int> ans;
        while(!pq.empty())
        {
            auto p  = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        followers[followerId].erase(followeeId);
    }
};
