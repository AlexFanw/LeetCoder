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

/*
 * 102.二叉树的层序遍历
 * tips：用一个变量保存每一层的节点数量，再用队列先进先出
 */

vector<vector<int>> Solution::levelOrder(TreeNode* root){
    if (root == nullptr){
        return {};
    }
    vector<TreeNode*> queue_tree{root};
    int count = 1;
    vector<vector<int>> result{vector<int>{root->val}};
    vector<int> temp;
    while (queue_tree.size() > 0){
        if (count > 0){
            TreeNode *start = queue_tree[0];
            if (start->left != nullptr){
                queue_tree.push_back(start->left);
                temp.push_back(start->left->val);
            }
            if (start->right != nullptr){
                queue_tree.push_back(start->right);
                temp.push_back(start->right->val);
            }
            queue_tree.erase(queue_tree.begin());
            --count;
        }else{
            result.push_back(temp);
            temp = {};
            count = queue_tree.size();
        }
    }
    return result;
}

/*
 * 121.买卖股票的最佳时机
 * tips: 保存历史最低点，和现在的价格进行相减。
 */
int Solution::maxProfit(vector<int>& prices){
    int min = prices[0];
    int max_profit = 0;
    for (int i = 0; i < prices.size(); ++i) {
        if (min > prices[i]){
            min = prices[i];
        }
        if (prices[i] - min > max_profit){
            max_profit = prices[i] - min;
        }
    }
    return max_profit;
}

/*
 * 20.有效的括号
 * tips: 栈
 */

bool Solution::isValid(string s){
    vector<char> st{};
    for (int i = 0; i < s.size(); ++i) {
        if (st.size() == 0) st.push_back(s[i]);
        if ((s[i] == ')' && st[st.size()-1] == '(')||
            (s[i] == ']' && st[st.size()-1] == '[')||
            (s[i] == '}' && st[st.size()-1] == '{')){
            st.erase(st.end()-1);
        }else{
            st.push_back(s[i]);
        }
    }
    if (st.size() == 0) return true;
    else return false;
}

/*
 * 141.环形链表
 * tips: 快慢指针
 */

bool Solution::hasCycle(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            return true;
        }
    }
    return false;
}

/*
 * 103.二叉树的锯齿形层序遍历
 * tips:节点放入vector的顺序不变，每层改变取出的顺序
 */
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root) {
    if (root == nullptr){
        return {};
    }
    vector<TreeNode*> queue_tree{root};
    int count = 1;
    vector<vector<int>> result{vector<int>{root->val}};
    vector<int> temp;
    bool direction = false;
    while (queue_tree.size() > 0){
        if (count > 0){
            TreeNode *start = queue_tree[0];
            queue_tree.erase(queue_tree.begin());
            if (start->left != nullptr){
                if (direction == true) temp.push_back(start->left->val);
                else temp.insert(temp.begin(), start->left->val);
                queue_tree.push_back(start->left);
            }
            if (start->right != nullptr){
                if (direction == true) temp.push_back(start->right->val);
                else temp.insert(temp.begin(), start->right->val);
                queue_tree.push_back(start->right);
            }
            --count;
        }else{
            result.push_back(temp);
            temp = {};
            count = queue_tree.size();
            direction = !direction;
        }
    }
    return result;
}

/*
 * 33.搜索旋转排序数组
 * tips: 类比快速排序，用递归空间消耗比较大，建议使用循环
 */

int Solution::search(vector<int>& nums, int target) {
    return Solution::searchQuick(nums, 0, nums.size()-1, target);
}

int Solution::searchQuick(vector<int>& nums, int begin, int end, int target){
    if (target == nums[begin]) return begin;
    if (target == nums[end]) return end;
    if (end - begin <= 1){
        return -1;
    }
    int mid = (begin + end) / 2;

    if (nums[begin] < nums[mid]){
        if (nums[begin] < target && target < nums[mid]){
            return searchQuick(nums, begin, mid ,target);
        }else{
            return searchQuick(nums, mid, end ,target);
        }
    }else{
        if (nums[mid] < target && target < nums[end]){
            return searchQuick(nums, mid, end ,target);
        }else{
            return searchQuick(nums, begin, mid ,target);
        }
    }
}

/*
 * 236. 二叉树的最近公共祖先
 * tips: 递归。如果left或者right命中，则返回root
 */
TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if (root == nullptr){
        return nullptr;
    }
    if (root == p || root == q){
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);;
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left == nullptr && right != nullptr){
        return right;
    }else if (left != nullptr && right == nullptr){
        return left;
    }else if (left != nullptr && right != nullptr){
        return root;
    } else
        return nullptr;
}

/*
 * 88.合并两个有序数组
 */

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int pivot = nums1.size() - 1;
    while(pivot >= 0){
        if (m-1 < 0){
            nums1[pivot] = nums2[n-1];
            --n;
        } else if (n-1 < 0){
            nums1[pivot] = nums1[m-1];
            --m;
        } else if (nums1[m-1] > nums2[n-1]){
            nums1[pivot] = nums1[m-1];
            --m;
        }else if (nums1[m-1] <= nums2[n-1]){
            nums1[pivot] = nums2[n-1];
            --n;
        }
        --pivot;
    }
}

/*
 * 5.最长回文子串
 * tips::中心拓展法，遍历每个中心节点，向外拓展
 */

string Solution::longestPalindrome(string s){
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); ++i) {
        auto [left1, right1] = Solution::expandAroundCenter(s, i, i);
        auto [left2, right2] = Solution::expandAroundCenter(s, i, i + 1);
        if (right1 - left1 > end - start) {
            start = left1;
            end = right1;
        }
        if (right2 - left2 > end - start) {
            start = left2;
            end = right2;
        }
    }
    return s.substr(start, end - start + 1);
}

std::pair<int, int> Solution::expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
    }
    return {left + 1, right - 1};
}
