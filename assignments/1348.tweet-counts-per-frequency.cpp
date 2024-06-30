class TweetCounts {
private:
map<string, vector<int>> tweetRecords;
public:

    
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        tweetRecords[tweetName].push_back(time);
        
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval;
        if(freq == "minute"){
            interval = 60;
        }else if(freq == "hour"){
            interval = 3600;
        }else if(freq == "day"){
            interval = 86400;
        }

        vector<int> times = tweetRecords[tweetName];
        sort(times.begin(), times.end());

        vector<int> result;
        for (int start = startTime; start <= endTime; start += interval) {
            int end = min(start + interval, endTime + 1);
            int count = count_if(times.begin(), times.end(), [start, end](int time) {
                return time >= start && time < end;
            });
            result.push_back(count);
        }
        return result;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */