package main

func removeDuplicates(nums []int) int {
    i := 0
    for _, num := range nums {
        if i < 2 || num > nums[i-2] { 
            nums[i] = num
            i++
        }
    }
    return i
}

// notice that if k duplicates if allowed, just replace 2 with k