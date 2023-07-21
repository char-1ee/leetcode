package main

func longestArithSeqLength(nums []int) int {
    n, mx := len(nums), 0
    dp := make([][]int, n)
    for i := range dp {
        dp[i] = make([]int, 1001)
    }

    for right := 0; right < n; right++ {
        for left := 0; left < right; left++ {
            diff := nums[left] - nums[right] + 500
            if dp[left][diff] > 0 {
                dp[right][diff] = dp[left][diff] + 1
            } else {
                dp[right][diff] = 2
            }
            if mx < dp[right][diff] {
                mx = dp[right][diff]
            }
        }
    }
    return mx
}