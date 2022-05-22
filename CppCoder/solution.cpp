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

/*
 * 25.K个一组翻转链表
 * tips: 递归法，把前面已经完成翻转的k个节点视作一个整体
 *       注意后续如果不满k个节点，就不要翻转了
 */

ListNode *Solution::reverseKGroup(ListNode *head, int k) {
    if (head == nullptr){
        return nullptr;
    }
    ListNode *first = head;
    ListNode *start = nullptr;
    ListNode *mid = head;
    ListNode *end = head->next;

    //检查后续是否还有K个节点
    ListNode *detect = head;
    for (int i = 0; i < k; i++){
        if (detect == nullptr){
            return first;
        }
        detect = detect->next;
    }

    for (int i = 0; i < k-1; i++){
        ListNode *next_end = end->next;
        mid->next = start;
        end->next = mid;
        start = mid;
        mid = end;
        end = next_end;
    }
    if (end != nullptr){
        first->next = reverseKGroup(end, k);
    }
    return mid;
}

/*
 * 15.三数之和
 * tips: 排序+双指针
 */

vector<vector<int>> Solution::threeSum(vector<int>& nums){
    vector<vector<int>> result;
    if (nums.size() < 3) return {};
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) break; //提前结束
        if (i > 0 && nums[i] == nums[i-1]) continue;

        int pivot = nums[i];
        int begin = i+1;
        int end = nums.size() - 1;

        while (begin < end) {
            if (pivot + nums[begin] + nums[end] > 0){
                while(begin < end && nums[end] == nums[end-1]) end -= 1; // 尾部去重
                end -= 1;
            }else if (pivot + nums[begin] + nums[end] <= 0){
                if (pivot + nums[begin] + nums[end] == 0){
                    result.push_back(vector<int>{pivot, nums[begin], nums[end]});
                }
                while(begin < end && nums[begin] == nums[begin+1]) begin += 1; // 头部去重
                begin += 1;
            }
        }
    }
    return result;
}

/*
 * 912.排序数组
 * tips: 快速排序，精髓在于碰到比pivot大的数字i，先将i和pivot后面一个数字交换，再和pivot交换。
 */
vector<int> Solution::sortArray(vector<int>& nums) {
    return quickSort(nums, 0, nums.size());
}

vector<int>& Solution::quickSort(vector<int>& nums, int start, int end){
    if (end - start <= 1){
        return nums;
    }
    int pivot = (rand() % (end-start))+ start;
    std::swap(nums[pivot], nums[start]);
    pivot = start;
    for (int i = start+1; i < end; ++i) {
        if (nums[i] < nums[pivot]){
            std::swap(nums[pivot+1], nums[i]);
            std::swap(nums[pivot], nums[pivot+1]);
            pivot += 1;
        }
    }
    quickSort(nums, start, pivot);
    quickSort(nums, pivot+1, end);
    return nums;
}

/*
 * 53.最大子序和
 * tips：负数则重开，正数则累加
 */

int Solution::maxSubArray(vector<int> &nums) {
    int max_sum = nums[0];
    int now_sum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (now_sum < 0){
            now_sum = nums[i];
        } else{
            now_sum += nums[i];
        }
        if (now_sum > max_sum){
            max_sum = now_sum;
        }
    }
    return max_sum;
}

/*
 * 21.合并两个有序链表
 * tips：递归法
 */

ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2){
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;
    if (list1->val >= list2->val){
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    } else{
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
}