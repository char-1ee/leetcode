// One pointer to scan, one pointer to overwrite
function removeDuplicates(nums: number[]): number {
    if (nums.length === 1) return 1;
    let k = 0;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] !== nums[k]) {
            nums[++k] = nums[i];
        }
    }
    return k + 1;
};