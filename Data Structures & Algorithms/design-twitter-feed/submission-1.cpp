class Twitter {
   public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        if (!userExists(userId)) {
            users.insert({userId, {}});
        }
        pair<int, int> res;
        res.first = globalClock;
        res.second = tweetId;
        users.at(userId).tweets.push_back(res);
        globalClock++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if (!userExists(userId)) return res;

        // extract a copy of data (tweets)
        vector<pair<int, int>> feed = users.at(userId).tweets;

        //now add every followees posts to the vector
        for (auto followee : users.at(userId).following) {
            for (auto tweet : users.at(followee).tweets) {
                feed.push_back(tweet);
            }
        }
        //sort by post time (.first)
        std::sort(feed.begin(), feed.end(),[](auto& a, auto& b){
            return a.first > b.first;
        });

        for (int i{}; i < 10 && i < feed.size(); i++) {
            res.push_back(feed[i].second);
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        users.try_emplace(followerId);
        users.try_emplace(followeeId);
        // both users exist, and 1 doesnt follow 2
        if (userExists(followerId) && userExists(followeeId)) {
            auto res = find(users.at(followerId).following.begin(), users.at(followerId).following.end(), followeeId);
            if (res != users.at(followerId).following.end()) return;

            users.at(followerId).following.push_back(followeeId);
        }

    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;

        // both users exist, and 1 follows 2
        if (userExists(followerId) && userExists(followeeId)) {
            auto res = find(users.at(followerId).following.begin(), users.at(followerId).following.end(), followeeId);
            if (res == users.at(followerId).following.end()) return;

            users.at(followerId).following.erase(res);
        }
    }

    // stores a users tweets, following
    struct data {
        // store time of post, as well as tweetId
        vector<std::pair<int, int>> tweets;
        // stores ids of users who user is following
        vector<int> following;
    };

    int globalClock{};

    // id,  data
    map<int, data> users;

    bool userExists(int userId) {
        if (users.find(userId) != users.end()) {
            return true;
        }
        return false;
    }
};
