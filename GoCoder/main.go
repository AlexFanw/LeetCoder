package main

import "fmt"

func main(){
	var s = [...]int{1,2,3,4,5,6}
	a := s[1:3]
	fmt.Println(len(a), cap(a))
	fmt.Println(s[1:3])
}