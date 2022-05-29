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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target); //1.两数之和：hash
    ListNode *reverseList(ListNode *head); //206.反转链: 三指针
    static int lengthOfLongestSubstring(string s); // 3.无重复字符的最长子串：双指针
    static int findKthLargest(vector<int> &nums, int k); // 215.数组中的第K个最大元素：快排
    static ListNode *
    reverseKGroup(ListNode *head, int k); //25.K个一组翻转链表 tips: 递归法，把前面已经完成翻转的k个节点视作一个整体，注意后续如果不满k个节点，就不要翻转了
    static vector<vector<int>> threeSum(vector<int> &nums); //15.三数之和 tips: 排序+双指针
    static vector<int> sortArray(vector<int> &nums); //912.排序数组
    static vector<int> &quickSort(vector<int> &nums, int start, int end); //912.快速排序
    static int maxSubArray(vector<int> &nums); //53.最大子序和 tips:负数则重开，正数则累加
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2); //21.合并两个有序链表 tips：递归法
    vector<vector<int>> levelOrder(TreeNode *root); // 102.二叉树的层序遍历：tips：用一个变量保存每一层的节点数量，再用队列先进先出
    static int maxProfit(vector<int> &prices); //121.买卖股票的最佳时机 tips: 保存历史最低点，和现在的价格进行相减。
    static bool isValid(string s); //20.有效的括号 tips:栈
    static bool hasCycle(ListNode *head); //141.环形链表，tips:快慢指针
    static vector<vector<int>> zigzagLevelOrder(TreeNode *root); //103.二叉树的锯齿形层序遍历 tips:tips:节点放入vector的顺序不变，每层改变取出的顺序
    static int search(vector<int> &nums, int target); //33.搜索旋转排序数组 tips: 类比快速排序，用递归空间消耗比较大，建议使用循环
    static int searchQuick(vector<int>& nums, int begin, int end, int target);
    static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q); //236.二叉树的最近公共祖先，tips: 递归。如果left或者right命中，则返回root
    static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);// 33.合并两个有序数组
};
#endif //CPPCODER_SOLUTION_H
