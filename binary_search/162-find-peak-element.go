func findPeakElement1(nums []int) int {
    size := len(nums)
    for i:= 1; i < size; i++ {
        if nums[i - 1] > nums[i] {
            return i - 1
        }
    }
    return size - 1
}