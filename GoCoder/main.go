package main

import (
	"fmt"
	"github.com/AlexFanw/LeetCoder/GoCoder/answer"
)

func main(){
	var x = []int{1,2,3,4,5,6}
	y := x
	y[0] = 99
	fmt.Println(answer.SortAnArray([]int{1,2,3}))
}