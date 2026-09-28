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

        int mid = vect.size()/2;
        int l{}, r = vect.size()- 1;
        int greatestIndex{-1};
        while (l <= r) {
            mid = l + (r-l)/2;
            if (vect[mid].second == timestamp) {
                return vect[mid].first;
            } else if (vect[mid].second < timestamp) {
                l = mid + 1;
                greatestIndex = mid;
            } else {
                r = mid - 1;
            }
        }

        if (greatestIndex != -1) return vect[greatestIndex].first;
        return "";
    }
    //key, all values and their timestamps sorted by timestamp asc
    std::unordered_map<std::string, std::vector<std::pair<string, int>>> data;
};
