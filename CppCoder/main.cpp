#include <iostream>
#include <vector>
#include "solution.h"
#include "LRUCache.h"
using std::vector;
using std::string;

int main() {
    string s = "(){}}{";
    std::cout << Solution::isValid(s) << std::endl;
}