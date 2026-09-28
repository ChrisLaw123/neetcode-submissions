class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (data.find(key) == data.end()) return "";
        auto& vect = data.at(key);
        for (int i = vect.size() - 1; i >= 0; i--) {
            if (vect[i].second <= timestamp) {
                return vect[i].first;
            }
        }
        return "";
    }
    //key, all values and their timestamps sorted by timestamp asc
    std::unordered_map<std::string, std::vector<std::pair<string, int>>> data;
};
