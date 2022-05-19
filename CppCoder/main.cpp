#include <iostream>
#include <vector>
#include "solution.h"
#include "LRUCache.h"
using std::vector;
using std::string;

int main() {
    vector<int> a = {11,2,35,47,5,16,17,68,29,0};
    std::cout << Solution::findKthLargest(a, 2) << std::endl;
}