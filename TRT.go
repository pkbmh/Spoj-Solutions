package main

import "fmt"

func solve(dp [][]int, arr []int, a, i, j int) int {
	if i == j {
		return arr[i] * a
	}
	if dp[i][j] != -1 {
		return dp[i][j]
	}

	l := solve(dp, arr, a+1, i+1, j) + arr[i]*a
	r := solve(dp, arr, a+1, i, j-1) + arr[j]*a
	if l < r {
		dp[i][j] = r
	} else {
		dp[i][j] = l
	}

	return dp[i][j]
}
func main() {
	var n int
	var t int
	_, err := fmt.Scanf("%d", &n)
	if err != nil {
		fmt.Println("Err in reading n")
	}
	arr := make([]int, 0)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &t)
		arr = append(arr, t)
	}
	//fmt.Println(arr)
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			dp[i][j] = -1
		}
	}

	fmt.Println(solve(dp, arr, 1, 0, n-1))
}
