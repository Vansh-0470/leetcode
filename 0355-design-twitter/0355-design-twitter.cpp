class Twitter {
public:
    vector<vector<int>> users;
    vector<pair<int,int>> q;

    Twitter() {
        users.resize(501);
    }

    void postTweet(int userId, int tweetId) {
        q.push_back({tweetId, userId});
    }

    bool isfollower(int id, int userId) {
        if(id == userId) return true;

        for(auto it : users[userId]) {
            if(it == id) return true;
        }

        return false;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        int count = 0;

        for(int i = q.size() - 1; i >= 0 && count < 10; i--) {
            int post = q[i].first;
            int user = q[i].second;

            if(isfollower(user, userId)) {
                ans.push_back(post);
                count++;
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].push_back(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        int idx = 0;

        for(auto it : users[followerId]) {
            if(it == followeeId) break;
            idx++;
        }

        if(idx == users[followerId].size()) return;

        users[followerId].erase(users[followerId].begin() + idx);
    }
};