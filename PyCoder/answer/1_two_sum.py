class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashdict = {}
        for i in range(len(nums)):
            if (target-nums[i]) in hashdict:
                return [i, hashdict[target-nums[i]]]
            hashdict[nums[i]] = i
        return []


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 9
    s = Solution()
    print(s.twoSum(nums, target))