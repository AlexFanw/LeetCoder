#include <iostream>
#include <vector>
#include "solution.h"
using std::vector;
using std::string;

int main() {
    int max_len = 0;
    int now_len = 0;
    string s = "abcabcbbasdfghjkl";
    std::cout << Solution::lengthOfLongestSubstring(s) <<std::endl;
}