class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> data;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        // search for the key
        // if found, push back a new pair to the vector
        // if not, initialize a new vector
        auto it = data.find(key);
        if (it != data.end()) {
            it->second.push_back(pair<int, string>(timestamp, value));
        } else {
            vector<pair<int, string>> v;
            v.emplace_back(timestamp, value);
            data.emplace(key, v);
        }
    }
    
    string get(string key, int timestamp) {
        auto it = data.find(key);
        if (it == data.end()) {
            // not found
            return "";
        }
        auto & p_vec = it->second;
        // binary search
        // l = 0, r = n - 1;
        // idx = -1; find the maximum idx <= timestamp
        // m = (l+r)/2
        // 
        // if [m].first < timestamp
        //      idx = max(idx, m);
        //      l = m + 1
        // if [m].first > timestamp
        //      r = m - 1
        // ==
        // idx = m, break
        int l = 0, r = p_vec.size() - 1;
        int idx = -1;
        while (l <= r) {
            int m = (l+r)/2;
            if (p_vec[m].first == timestamp) {
                idx = m;
                break;
            } else if (p_vec[m].first < timestamp) {
                idx = max(idx, m);
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (idx != -1) {
            return p_vec[idx].second;
        }
        return "";
        
    }
};
