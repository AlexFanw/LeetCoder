#include <iostream>
#include <vector>
#include "solution.h"
using std::vector;
using std::string;

int main() {
    vector<int> nums = {0,1,2};
    vector<vector<int>> result = Solution::permute(nums);
    for (auto &i: result) {
        for (auto j: i){
            std::cout << j;
        }
        std::cout << std::endl;
    }
}