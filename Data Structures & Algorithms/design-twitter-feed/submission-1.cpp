class Twitter {
    // follow hash_map<userID:int, followee_ID:unordered_set<int>>
    // Tweet_data hash_map<userID:int, tweet: vector<timestamp:int, tweetId:int>>
    // all_news_feed hash_map<userId: int, feed: priority_queue<pair<int,int>>>
    // timestamp: int
    int timestamp;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweet_data;
    unordered_map<int, priority_queue<pair<int,int>>> own_news_feed;

public:
    Twitter() {
        this->timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        this->tweet_data[userId].push_back({-this->timestamp, tweetId});
        this->own_news_feed[userId].push({-this->timestamp, tweetId});
        if (this->own_news_feed[userId].size() > 10) {
            this->own_news_feed[userId].pop();
        }
        this->timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        auto & followeeIds = following[userId];
        priority_queue<pair<int, int>> news_feed_q = this->own_news_feed[userId];
        for (auto id : followeeIds) {
            if (id == userId) {
                continue;
            }
            cout << "userId: " << userId << ", followeeId: " << id << endl;
            for (auto & pr : tweet_data[id]) {
                cout << "followeeId: " << id << ", tweetId: " << pr.second << endl;
                news_feed_q.push({pr.first, pr.second});
                if (news_feed_q.size() > 10) {
                    news_feed_q.pop();
                }
            }
        }
        int size = news_feed_q.size();
        vector<int> ans(size, 0);
        for (int i = size-1; i>=0; --i) {
            ans[i] = news_feed_q.top().second;
            news_feed_q.pop();
        }

        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
