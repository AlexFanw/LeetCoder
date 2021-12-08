package main

import (
	"fmt"
	"reflect"
)

type behavior interface {
	eat(string) string
	sleep(string) string
}

type ivy struct {
	a int
	b string
}

func (i *ivy) eat(si string)(sr string){
	sr = si
	return
}

func (i *ivy) sleep(si string)(sr string){
	sr = si
	return
}

func main(){
	var i behavior = new(ivy)
	fmt.Println(i.eat("eat banana"))
	//fmt.Println(i.a) //报错，这里是访问不到ivy里面的值的
	var x interface{} = 1
	fmt.Println(reflect.TypeOf(x))
	x = "123"
	fmt.Println(reflect.TypeOf(x))
}