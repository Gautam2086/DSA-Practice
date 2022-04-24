class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkInTime;    // [id, {place, time}]
    unordered_map<string, pair<int, int>> checkOutTime;   // [place1->place2, {abs time, no.of travels}]
    
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInTime[id]= {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string key= "";
        key += checkInTime[id].first + "->" + stationName;
        
        int time= t - checkInTime[id].second;
        int travels= 0;
        
        if(checkOutTime.find(key) != checkOutTime.end())
        {
            time += checkOutTime[key].first;
            travels= checkOutTime[key].second;
        }
        
        checkOutTime[key]= {time, travels+1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key= "";
        key += startStation + "->" + endStation;
        
        return (double)checkOutTime[key].first/checkOutTime[key].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */