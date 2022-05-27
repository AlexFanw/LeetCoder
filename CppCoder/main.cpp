#include <iostream>
#include <vector>
#include "solution.h"
#include "LRUCache.h"
using std::vector;
using std::string;

int main() {
    vector<int> a{4,5,6,7,0,1,2};
    int target = 2;
    std::cout << Solution::search(a, target) << std::endl;
}