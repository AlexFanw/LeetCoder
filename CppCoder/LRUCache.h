//
// Created by 范唯 on 2022/5/18.
//

#ifndef CPPCODER_LRUCACHE_H
#define CPPCODER_LRUCACHE_H

#include <unordered_map>
using std::unordered_map;
struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
    void moveToHead(DLinkedNode *node);
    void addToHead(int key, int value);
    void deleteTail();

private:
    size_t capacity;
    size_t size;
    DLinkedNode *head;
    DLinkedNode *tail;
    unordered_map<int, DLinkedNode*> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 * The functions get and put must each run in O(1) average time complexity.
 */


#endif //CPPCODER_LRUCACHE_H
