class Solution {
    /**
     * Two people climb from left and from right separately. 
     * If they are climbing the same mountain, they will meet at the same point.
     * --lee215
     */
    public boolean validMountainArray(int[] arr) {
        int n = arr.length, i = 0, j = n - 1;
        while (i < n - 1 && arr[i + 1] > arr[i])
            i++;
        while (j > 0 && arr[j - 1] > arr[j])
            j--;
        // Restriction for n < 3.
        return i == j && i > 0 && j < n - 1;
    }
}
