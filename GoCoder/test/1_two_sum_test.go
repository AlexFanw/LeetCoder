package test

import (
	"fmt"
	"github.com/AlexFanw/LeetCoder/GoCoder/answer"
	"testing"
)

func TestTwoSum(t *testing.T){
	a := answer.TwoSum(TWO_SUM_NUMS, TWO_SUM_TARGET)
	fmt.Println(a)
}