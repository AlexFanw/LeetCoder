#include <iostream>
#include <vector>
#include "solution.h"
using std::vector;
using std::string;

int main() {
    std::cout << 9333852702227987 + 85731737104263 << std::endl;
    string num1 = "9333852702227987";
    string num2 = "85731737104263";
    std::cout << Solution::addStrings(num1, num2) << std::endl;
}