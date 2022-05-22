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
    vector<int> twoSum(vector<int>& nums, int target); //1.两数之和：hash
    ListNode* reverseList(ListNode* head); //206.反转链: 三指针
    static int lengthOfLongestSubstring(string s); // 3.无重复字符的最长子串：双指针
    static int findKthLargest(vector<int>& nums, int k); // 215.数组中的第K个最大元素：快排
    static ListNode* reverseKGroup(ListNode* head, int k); //25.K个一组翻转链表 tips: 递归法，把前面已经完成翻转的k个节点视作一个整体，注意后续如果不满k个节点，就不要翻转了
    static vector<vector<int>> threeSum(vector<int>& nums); //15.三数之和 tips: 排序+双指针
    static vector<int> sortArray(vector<int>& nums); //912.排序数组
    static vector<int>& quickSort(vector<int>& nums, int start, int end); //912.快速排序
    static int maxSubArray(vector<int>& nums); //53.最大子序和 tips:负数则重开，正数则累加
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2); //21.合并两个有序链表 tips：递归法
};


#endif //CPPCODER_SOLUTION_H
