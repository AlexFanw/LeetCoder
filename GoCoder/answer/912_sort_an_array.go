package answer

import (
	"math/rand"
)

func SortAnArray(nums []int) []int {
	if len(nums) <= 1{
		return nums
	}
	random_flag := rand.Intn(len(nums))
	flag := nums[random_flag]
	l_list := [ ]int{}
	r_list := [ ]int{}
	nums = append(nums[:random_flag], nums[random_flag+1:]...)
	for _, v := range nums{
		if v < flag{
			l_list = append(l_list, v)
		}else {
			r_list = append(r_list, v)
		}
	}
	return append(append(SortAnArray(l_list), flag), SortAnArray(r_list)...)
}
