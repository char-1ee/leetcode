func findMin(nums []int) int {
    n := len(nums)
    left, right, ans := 0, n - 1, -1   
	
    for left <= right {
        mid := (left + right) / 2
        if nums[mid] > nums[n - 1] {
            left = mid + 1
        } else {
            right = mid - 1
            ans = mid
        }
    }
    return nums[ans]
}