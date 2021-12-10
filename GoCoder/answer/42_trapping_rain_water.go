package answer

import "fmt"

func Trap(height []int) int {
	left_max := 0
	left_height := []int{}
	right_max := 0
	right_height := []int{}
	lenH := len(height)
	sumResult := 0
	for i := 0; i <= (lenH - 1) ; i ++ {
		if height[i] > left_max{
			left_max = height[i]
		}
		left_height = append(left_height, left_max)

		if height[lenH-i-1] > right_max{
			right_max = height[lenH-i-1]
		}
		right_height = append(right_height, right_max)
	}
	for k,_ := range height{
		if left_height[k] < right_height[lenH-k-1]{
			sumResult += left_height[k] - height[k]
		}else {
			sumResult += right_height[lenH-k-1] - height[k]
		}
	}
	fmt.Println(left_height, right_height)
	fmt.Println(sumResult)
	return sumResult
}