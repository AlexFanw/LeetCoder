package answer

import (
	"fmt"
	"sort"
)

func ThreeSum(nums []int) [][]int {
	result := [][]int{}
	sort.Ints(nums)
	if len(nums) < 3{
		return [][]int{}
	}
	for first, _ := range nums[:len(nums)-2]{
		if first>0 && nums[first] == nums[first-1]{ //选择第一个未重复的元素
			continue
		}
		third := len(nums) - 1
		second:=first+1
		for second != third{
			sumNow := nums[first] + nums[second] + nums[third]
			if sumNow == 0{
				result = append(result, []int{nums[first], nums[second], nums[third]})
			} else if sumNow > 0{
				for second != third{
					third--
					if nums[third] != nums[third+1]{
						break
					}
				}
				continue
			}
			for second != third{ // sumNow < 0 和sumNom == 0时都右移second
				second++
				if nums[second] != nums[second-1]{
					break
				}
			}
		}
	}
	fmt.Println(result)
	return result
}