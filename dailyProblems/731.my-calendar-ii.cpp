class MyCalendarTwo {
    private:
    vector<pair<int, int>>events;
    vector<pair<int, int>>doubleBooking;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(pair<int,int>p:doubleBooking){
            if(start<p.second && end>p.first)
                return false;
        }

        for(pair<int,int>p:events){
            if(start<p.second && end>p.first)
                doubleBooking.push_back({max(start,p.first),min(end,p.second)});
        }
        events.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */