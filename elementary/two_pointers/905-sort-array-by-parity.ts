// Two-pointers (towards each other)
function sortArrayByParity(nums: number[]): number[] {
    if (nums.length === 1) return nums;
    for (let i = 0, j = nums.length - 1; i < j;) {
        while (i < j && nums[i] % 2 === 0) {
            i++;
        }
        while (i < j && nums[j] % 2 !== 0) {
            j--;
        }
        if (i < j) {
            [nums[i], nums[j]] = [nums[j], nums[i]];
        }
    }
    return nums;
};

// Two-pointers (same direction) - same as 288-move-zeros
function sortArrayByParity2(nums: number[]): number[] {
    if (nums.length === 1) return nums;
    for (let i = 0, j = 0; i < nums.length; i++) {
        if (nums[i] % 2 === 0) {
            [nums[i], nums[j]] = [nums[j], nums[i]];
            j++;
        }
    }
    return nums;
};