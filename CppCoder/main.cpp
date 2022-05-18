#include <iostream>
#include <vector>
#include "solution.h"
#include "LRUCache.h"
using std::vector;
using std::string;

int main() {
    LRUCache *lru = new LRUCache(2);
    lru->put(1,1);
    std::cout << lru->get(1) << std::endl;
    lru->put(2,2);
    lru->put(3,3);
    std::cout << lru->get(3) << std::endl;
    std::cout << lru->get(2) << std::endl;
    std::cout << lru->get(1) << std::endl;
}