package main

func nextPermutation(nums []int)  {
    n := len(nums)
    for i := n - 2; i >= 0; i-=1 {
        if nums[i + 1] <= nums[i] {
            continue
        } 
        j := n - 1
        for ; j > i; j-=1 {
            if nums[j] > nums[i] {
                break
            }
        }
        nums[i], nums[j] = nums[j], nums[i]
        // sort.Ints(nums[i+1:])
        reverse(nums, i + 1, n - 1)
        return
    }
    reverse(nums, 0, n - 1)
}

func reverse(nums []int, start int, end int) {
    for i, j := start, end; i < j; i, j = i+1, j-1 {
        nums[i], nums[j] = nums[j], nums[i]
    }
}