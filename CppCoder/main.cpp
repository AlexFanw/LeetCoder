#include <iostream>
#include <vector>
#include "solution.h"
using std::vector;
int main() {
    Solution *s = new Solution();
    vector<int> inpt = {3,2,4,5,7,0};
    int target = 12;
    vector<int> a = s->twoSum(inpt, target);
    for (int x: a) {
        std::cout << x <<std::endl;
    }
}