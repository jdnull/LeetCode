//
//  main.cpp
//  test
//
//  Created by JiaDuan on 14-8-23.
//  Copyright (c) 2014年 jdnull. All rights reserved.
//

#include <list>
#include <map>
#include <iostream>

using namespace std;

class Cache {
public:
    int key;
    int value;
    Cache(int k, int v) : key(k), value(v) {}
};

class LRUCache{
private:
    int capacity;
    list<Cache *> cacheList;
    map<int, list<Cache *>::iterator> keyListIt;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        map<int, list<Cache *>::iterator>::iterator mapIt = keyListIt.find(key);
        if (mapIt == keyListIt.end()) {
            return -1;
        }
        
        int returnValue = (*(mapIt->second))->value;
        cacheList.erase(mapIt->second);
        keyListIt.erase(key);
        
        Cache *c = new Cache(key, returnValue);
        cacheList.push_front(c);
        keyListIt.insert(pair<int, list<Cache *>::iterator>(key, cacheList.begin()));
        return returnValue;
    }
    
    void set(int key, int value) {
        Cache *c = new Cache(key, value);
        map<int, list<Cache *>::iterator>::iterator mapIt = keyListIt.find(key);
        
        if (mapIt != keyListIt.end()) { // in case to insert an existing key
            cacheList.erase(mapIt->second);
            keyListIt.erase(key);
        } else {
            if (cacheList.size() + 1 > this->capacity) {
                list<Cache *>::reverse_iterator rListIt = cacheList.rbegin();
                keyListIt.erase((*rListIt)->key);
                cacheList.pop_back();
            }
        }
        
        cacheList.push_front(c);
        keyListIt.insert(pair<int, list<Cache *>::iterator>(key, this->cacheList.begin()));
    }
};

int main(int argc, const char * argv[])
{
    LRUCache lru = LRUCache(1);
    lru.set(2,1);
    cout << lru.get(2) << endl;
    lru.set(3,2);
    cout << lru.get(2) << endl;
    cout << lru.get(3) << endl;
    
    cout << "finish" << endl;
    return 0;
}

