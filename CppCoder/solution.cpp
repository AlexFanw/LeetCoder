//
// Created by 范唯 on 2022/5/10.
//
#include <iostream>
#include "solution.h"
#include <map>
using std::cout;
using std::map;
/*
 * 1.两数之和
 */
vector<int> Solution::twoSum(vector<int> &nums, int target) {
    map<int, int> hash_two;
    for (int i = 0; i < nums.size(); i++) {
        if (hash_two.find(target-nums[i]) == hash_two.end()){
            hash_two[nums[i]] = i;
        } else{
            return vector<int>{hash_two[target-nums[i]], i};
        }
    }
    return {};
}

/*
 * 206.反转链表
 */
ListNode* Solution::reverseList(ListNode* head) {
    if (head == nullptr){
        return head;
    }
    ListNode *a_node = nullptr;
    ListNode *b_node = head;
    ListNode *c_node = head->next;
    while(c_node != nullptr){
        ListNode *temp = c_node->next;

        b_node->next = a_node;
        c_node->next = b_node;
        a_node = b_node;
        b_node = c_node;
        c_node = temp;
    }
    return b_node;
};