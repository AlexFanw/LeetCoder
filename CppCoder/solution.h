//
// Created by 范唯 on 2022/5/10.
//

#ifndef CPPCODER_SOLUTION_H
#define CPPCODER_SOLUTION_H

#include <vector>
#include "string"
using std::vector;
using std::string;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target);
    ListNode* reverseList(ListNode* head);
    static int lengthOfLongestSubstring(string s);
    static int findKthLargest(vector<int>& nums, int k);
    static ListNode* reverseKGroup(ListNode* head, int k);
    static vector<vector<int>> threeSum(vector<int>& nums);
    static vector<int>& quickSort(vector<int>& nums, int start, int end);
};


#endif //CPPCODER_SOLUTION_H
