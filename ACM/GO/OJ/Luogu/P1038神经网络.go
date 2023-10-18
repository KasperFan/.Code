package main

import (
	"fmt"
)

const N int = 110
const M int = N * N

var h [N]int
var e [M]int
var w [M]int
var ne [M]int
var idx int

var c [N]int
var u [N]int
var in [N]int
var out [N]int

var q = make([]int, 0)

func add(a, b, c int) {
	e[idx] = b
	w[idx] = c
	ne[idx] = h[a]
	h[a] = idx
	idx++
}

func init() {
	for i := 0; i < N; i++ {
		h[i] = -1
	}
}

func main() {
	var n, p int
	fmt.Scanf("%d %d", &n, &p)
	fmt.Scanln()
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d %d", &c[i], &u[i])
	}
	for i := 1; i <= p; i++ {
		var a,b,c int
		fmt.Scanf("%d %d %d", &a, &b, &c)
		add(a, b, c)
		out[a]++
		in[b]++
	}
	for i := 1; i <= n; i++ {
		if in[i] == 0 {
			q = append(q, i)
		} else {
			c[i] -= u[i]
		}
	}
	for len(q) > 0 {
		j := q[0]
		q = q[1:]
		for k := h[j]; k != -1; k = ne[k] {
			i := e[k]
			cc := w[k]
			if c[j] >= 0 {
				c[i] += cc * c[j]
			}
			in[i]--
			if in[i] == 0 {
				q = append(q, i)
			}
		}
	}
	has := false
	for i := 1; i <= n; i++ {
		if out[i] == 0 {
			if c[i] > 0 {
				fmt.Printf("%d %d\n", i, c[i])
				has = true
			}
		}
	}
	if !has {
		fmt.Println("NULL")
	}
}
