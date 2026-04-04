class LRUCache {
    // use a list for key, value pair, doubly linked list
    // use a hash map the find the node of the list easily O(1)
    list<pair<int, int>> cache; // key, vale
    unordered_map<int, list<pair<int, int>>::iterator> hmap;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto p = hmap.find(key);
        if (p == hmap.end()) {
            // the key doesn't exist
            return -1;
        } else {
            auto it = p->second;
            cache.splice(cache.begin(), cache, it);
            if (it != cache.begin()) {
                cout << "they are not the same! " << endl;
            }
            return it->second;
        }
    }
    
    void put(int key, int value) {
        // first put the key into the cache,
        // then check the capacity against the size of the cache
        auto p_map = hmap.find(key);
        if (p_map == hmap.end()) {
            // not found
            if (this->capacity == cache.size()) {
                // remove the <key, it> in the hmap
                hmap.erase(cache.back().first);
                // remove the last element in the cache
                cache.pop_back();
            }
            cache.push_front({key, value});
            auto p_cache = cache.begin();
            hmap.emplace(key, p_cache);
        } else {
            // found
            // update the value
            auto it = p_map->second;
            it->second = value;
            // move the pair to the front
            cache.splice(cache.begin(), cache, it);
        }
    }
};
