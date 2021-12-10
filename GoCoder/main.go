package main

import (
	"fmt"
	"io"
	"log"
	"net"
	"time"
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

func main() {
	//监听8000这个端口
	listener, err := net.Listen("tcp", "localhost:8000")
	if err != nil {
		log.Fatal(err)
	}
	//Accept会阻塞main函数，并在有连接进来时继续执行
	for {
		conn, err := listener.Accept()
		if err != nil {
			log.Print(err) // e.g., connection aborted
			continue
		}
		go handleConn(conn) // handle one connection at a time
		//用handleConn处理这个连接
	}
}
func handleConn(c net.Conn) {
	defer func(c net.Conn) {
		err := c.Close()
		fmt.Println("连接已断开")
		if err != nil {

		}
	}(c) //conn关闭时断开连接
	for {
		_, err := io.WriteString(c, time.Now().Format("15:04:05\n")) //把格式化time写入c连接
		if err != nil {
			return // e.g., client disconnected
		}
		time.Sleep(1 * time.Second) //每间隔一秒写入当前时间
	}
}