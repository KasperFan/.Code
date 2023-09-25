package main

import "fmt"

func main() {
	var n int
	var sum = 0
	fmt.Scanf("%d", &n)
	for i := 1; i <= n; i++ {
		sum += i
	}
	fmt.Printf("%d\n", sum)
}
