//
//  No.146.LRUCache.h
//  LeetCode
//
//  146. LRU缓存机制
//  https://leetcode-cn.com/problems/lru-cache/
//  Created by baiya on 2020/3/22.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No_146_LRUCache_h
#define No_146_LRUCache_h

#include <map>
#include <vector>

// TODO unorder_map && list && pair
class LRUCache {
public:

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    ~LRUCache() {
        cache.clear();
        map.clear();
    }
    
    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1;
        pair<int, int> kv = *map[key];
        cache.erase(map[key]);
        cache.push_front(kv);
        
        map[key] = cache.begin();
        return kv.second;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if (it == map.end()) {
            if (cap == cache.size()) {
                auto last = cache.back();
                map.erase(last.first);
                cache.pop_back();
            }
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        } else {
            cache.erase(map[key]);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
    }
    
private:
    list<pair<int, int>> cache; // key - value
    unordered_map<int, list<pair<int, int>>::iterator> map;
    int cap;
};

#endif /* No_146_LRUCache_h */
