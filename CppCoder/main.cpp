#include <iostream>
#include <vector>
#include "solution.h"
using std::vector;
using std::string;

int main() {
    string s = "aacabdkacaa";
    std::cout << Solution::longestPalindrome(s) << std::endl;
}