package answer

func MaxSubArray(nums []int) int {
	//@description : 试着倒过来看
	// f(k) = Max{f(k-1)+num[k], f(k-1)}
	// 这里的f(k)其实就是num[k]，遍历过程中会更改num上每一位成为它的最大值
	if len(nums) == 0{
		return 0
	}
	max_sum := nums[0]
	for k,_ := range nums{
		if k == 0{
			continue
		}
		if nums[k]+nums[k-1] > nums[k]{
			nums[k] = nums[k] + nums[k-1]
		}
		if nums[k] > max_sum{
			max_sum = nums[k]
		}
	}
	return max_sum
}