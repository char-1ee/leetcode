// ===== Two-pointers: in-place changes =====
function moveZeroes(nums: number[]): void {
    if (nums.length === 1) return;

    for (let i = 0, j = 0; j < nums.length; j++) {
        if (nums[j] !== 0) {
            [nums[i], nums[j]] = [nums[j], nums[i]];
            i++;
        }
    }
};

// ===== Two-pointers: push non-zeros to front =====
function moveZeroes2(nums: number[]): void {
    if (nums.length == 1) return;

    // Push all non-zero elements to the front of array
    let idx = 0; // pointer to the position to place next non-zero element
    let i; // pointer for scanning
    for (i = 0; i < nums.length; i++) {
        if (nums[i] !== 0) {
            nums[idx++] = nums[i];
        }
    }

    // Now all non-zero elements are in their places, change rest of elements to zeros
    for (i = idx; i < nums.length; i++) {
        nums[i] = 0;
    }
};