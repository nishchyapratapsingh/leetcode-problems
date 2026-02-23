
class LRUCache {
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    int capacity;
public:
    LRUCache(int capacity) {
        // your implementation
        this ->  capacity = capacity;
    }

    int get(int key) {
        // your implementation
        if (cache.find(key) != cache.end()) {
            auto it = cache[key];
            int value = it->second;
            lru.erase(it);

            lru.push_front({key, value});
            cache[key] = lru.begin();

            return value;
        }
        return -1;
    }

    void put(int key, int value) {
        // your implementation

        if (cache.find(key) != cache.end()) {
                auto it = cache[key];
                lru.erase(it);

                lru.push_front({key, value});
                cache[key] = lru.begin();
        }

        else if (lru.size() < capacity) {
            lru.push_front({key, value});
            cache[key] = lru.begin();
        }

        else {
            auto it = lru.back();
            cache.erase(it.first);
            lru.pop_back();

            lru.push_front({key, value});
            cache[key] = lru.begin();
        }
    }
};