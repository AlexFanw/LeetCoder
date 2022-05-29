#include <iostream>
#include <vector>
#include "solution.h"
#include "LRUCache.h"
using std::vector;
using std::string;

int main() {
    vector<int> a{1,2,3,0,0,0};
    vector<int> b{2,5,6};
    Solution::merge(a, 3, b ,3);
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << std::endl;
    }
}