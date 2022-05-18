//
// Created by 范唯 on 2022/5/18.
//

#include <iostream>
#include "LRUCache.h"
/*
 * 146. LRU缓存机制
 * tips: 双链表 + map，使用map快速定位到node，使用双链表快速删除least used的node
 */


LRUCache::LRUCache(int _capacity): capacity(_capacity), size(0){
    head = new DLinkedNode();
    tail = new DLinkedNode();
    head->next = tail;
    tail->prev = head;
}

int LRUCache::get(int key) {
    if(!cache.count(key)){
        return -1;
    } else{
        DLinkedNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }
}

void LRUCache::put(int key, int value) {
    if (cache.find(key) != cache.end()){ //key存在
        DLinkedNode *node = cache.at(key);
        node->value = value;
        moveToHead(cache.at(key));
    }else{ //key不存在
        if (size < capacity) { //容量未满时添加至头部
            addToHead(key, value);
        } else{ //容量满时添加至尾部
            deleteTail();
            addToHead(key, value);
        }
    }
}

void LRUCache::moveToHead(DLinkedNode *node) {
    DLinkedNode *next_node = node->next;
    DLinkedNode *prev_node = node->prev;
    prev_node->next = next_node;
    next_node->prev = prev_node;

    DLinkedNode *head_next = head->next;

    node->next = head_next;
    node->prev = head;
    head->next = node;
    head_next->prev = node;
}

void LRUCache::addToHead(int key, int value){
    DLinkedNode *new_node = new DLinkedNode(key, value);
    DLinkedNode *head_next = head->next;
    head->next = new_node;
    new_node->next = head_next;
    head_next->prev = new_node;
    new_node->prev = head;
    cache[key] = new_node;
    ++size;
}

void LRUCache::deleteTail() {
    DLinkedNode *tail_prev = tail->prev;
    DLinkedNode *tail_prev_prev = tail->prev->prev;
    tail->prev = tail_prev_prev;
    tail_prev_prev->next = tail;
    cache.erase(tail_prev->key);
    delete tail_prev;
    --size;
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */