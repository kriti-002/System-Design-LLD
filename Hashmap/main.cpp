#include<bits/stdc++.h>

class MyHashMap {
public:
    vector<int>hash;
    int size=1000001;
    MyHashMap() {
        hash.resize(size, -1);
    }
    
    void put(int key, int value) {
        hash[key]=value;
    }
    
    int get(int key) {
        return hash[key];
    }
    
    void remove(int key) {
        hash[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */