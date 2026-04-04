class HitCounter {
    // use a hash_map to record hits at timestamps
    // use a vector to record the unique timestamp, the vector is sorted
    // then the hit is O(1)
    // to get the hits, 
    //      calculate the starting_timestamp
    //      check the vector from the end to the beginning, find the timestamps
    //      between the starting_timestamp and the timestamp
    //      sum up the timestamps
    // getHits O(300)
private:
    vector<int> t_stamps;
    unordered_map<int, int> hits_hmap; //<timestamp, hits>
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        hits_hmap[timestamp]++;
        if (t_stamps.empty()) {
            t_stamps.push_back(timestamp);
        } else if (t_stamps.back() == timestamp) {
            // do nothing
        } else {
            t_stamps.push_back(timestamp);
        }
    }
    
    int getHits(int timestamp) {
        int start_timestamp = max(1, timestamp-300+1);
        cout << "start_timestamp: " << start_timestamp << endl;
        int hits = 0;
        for (int i = t_stamps.size()-1; i >= 0; --i) {
            if (t_stamps[i] >= start_timestamp && t_stamps[i] <= timestamp) {
                hits += hits_hmap[t_stamps[i]];
            }
        }
        return hits;
        
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
