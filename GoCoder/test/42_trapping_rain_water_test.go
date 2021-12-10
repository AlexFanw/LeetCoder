package test

import (
	"github.com/AlexFanw/LeetCoder/GoCoder/answer"
	"testing"
)

func TestTrap(t *testing.T){
	s := []int{0,1,0,2,1,0,1,3,2,1,2,1}
	answer.Trap(s)
}