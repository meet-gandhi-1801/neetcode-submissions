class Twitter {
public:
    int timer;

    unordered_map<int, unordered_set<int>> following;

    // {timestamp, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
        following[userId].insert(userId);
    }

    vector<int> getNewsFeed(int userId) {

        // {time,{userId,index}}
        priority_queue<
            pair<int,pair<int,int>>
        > pq;

        // Push latest tweet of every followed user
        for(auto user : following[userId])
        {
            if(tweets[user].empty()) continue;

            int idx = tweets[user].size() - 1;

            pq.push({
                tweets[user][idx].first,
                {user, idx}
            });
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10)
        {
            auto cur = pq.top();
            pq.pop();

            int user = cur.second.first;
            int idx  = cur.second.second;

            ans.push_back(tweets[user][idx].second);

            // Push previous tweet of same user
            if(idx > 0)
            {
                pq.push({
                    tweets[user][idx-1].first,
                    {user, idx-1}
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].erase(followeeId);
    }
};