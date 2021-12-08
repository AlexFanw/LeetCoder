package test

import (
	"fmt"
	"github.com/AlexFanw/LeetCoder/GoCoder/answer"
	"testing"
)

func TestMaxSubArray(t *testing.T){
	nums := []int{-2,1,-3,4,-1,2,1,-5,4}
	fmt.Println(answer.MaxSubArray(nums))
}