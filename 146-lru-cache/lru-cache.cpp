#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    int capacity;

    list<pair<int, int>> l;

    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {

        // Key not present
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // Get iterator
        auto it = mp[key];

        // Move this item to front
        l.splice(l.begin(), l, it);

        return it->second;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            auto it = mp[key];

            // Update value
            it->second = value;

            // Move to front
            l.splice(l.begin(), l, it);

            return;
        }

        // Cache is full
        if (l.size() == capacity) {

            // Last element = least recently used
            auto last = l.back();

            // Remove from map
            mp.erase(last.first);

            // Remove from list
            l.pop_back();
        }

        // Insert new item at front
        l.push_front({key, value});

        // Store its iterator
        mp[key] = l.begin();
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */