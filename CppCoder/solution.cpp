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
 * tips: hash
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
 * tips: 三指针
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

/*
 * 3.无重复字符的最长子串
 * 双指针
 */

int Solution::lengthOfLongestSubstring(string s) {
    int max_len = 0;
    int now_len = 0;
    int beg = 0;
    for (int i = 0; i < s.length(); ++i){
        if(s.substr(beg, now_len).find(s[i]) == string::npos){
            now_len += 1;
        } else{
            beg = s.substr(beg, now_len).find(s[i]) + 1 + beg;
            now_len = i + 1 - beg;
        }
        if (max_len < now_len){
            max_len = now_len;
        }
    }
    return max_len;
}

/*
 * 215.数组中的第K个最大元素
 */

int Solution::findKthLargest(vector<int>& nums, int k){
    if (nums.size() < k){
        return 0;
    }
    vector<int> left, right;
    int r = (rand() % (nums.size()));
    int mid = nums[r];
    for (int i = 0; i < nums.size(); ++i) {
        if (i == r){
            continue;
        }else if (nums[i] < mid){
            left.push_back(nums[i]);
        } else{
            right.push_back(nums[i]);
        }
    }
    if (right.size() == k-1){
        return mid;
    }else if(right.size() > k-1){
        return findKthLargest(right, k);
    }else{
        return findKthLargest(left, k-right.size()-1);
    }
}