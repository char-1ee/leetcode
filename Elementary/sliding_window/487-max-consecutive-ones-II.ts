// Sliding window can cover all cases when scanning
function findMaxConsecutiveOnes(nums: number[]): number {
    let numOfZeros: number = 0;
    let left: number = 0, right: number = 0;
    let longestSeq: number = 0;

    while (right < nums.length) {
        if (nums[right] === 0) {
            numOfZeros++;
        }

        while (numOfZeros > 1) {
            if (nums[left] === 0) {
                numOfZeros--;
            }
            left++;
        }

        longestSeq = Math.max(longestSeq, right - left + 1);
        right++;
    }

    return longestSeq;
};

// Brute force
function findMaxConsecutiveOnes2(nums: number[]): number {
    let res: number = 0;
    let cntBeforeFlipZero: number = 0;
    let cntAfterFlipZero: number = 0;
    
    for (let i = 0; i < nums.length; i++) {
        cntAfterFlipZero++;
        if (nums[i] === 0) {
            cntBeforeFlipZero = cntAfterFlipZero;
            cntAfterFlipZero = 0;
        }
        res = Math.max(res, cntAfterFlipZero + cntBeforeFlipZero);   
    } 
    return res;
};