from typing import List


class Solution15:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        print(nums)
        result = []
        if len(nums) < 3:
            return result
        for first in range(len(nums)-2):
            if first > 0 and nums[first] == nums[first-1]:
                continue
            second = first + 1
            third = len(nums) - 1
            while second < third:
                sumNow = nums[first] + nums[second] + nums[third]
                if sumNow == 0:
                    result.append([nums[first], nums[second], nums[third]])
                elif sumNow < 0:
                    while second < third and nums[second] == nums[second+1]:
                        second += 1
                    second += 1
                    continue
                while second < third and nums[third] == nums[third-1]:
                    third -= 1
                third -= 1
        return result


if __name__ == "__main__":
    s = Solution15()
    print(s.threeSum([1, 0, -1, 2, -1]))
