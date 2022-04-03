package sorting;

import java.util.Random;

/** Quick sort: https://algs4.cs.princeton.edu/23quicksort/Quick.java.html */
class QuickSort {
    public int[] sortArray(int[] nums) {
        shuffle(nums);
        sort(nums, 0, nums.length - 1);
        return nums;
    }

    private static void sort(int[] nums, int lo, int hi) {
        if (lo >= hi)
            return;

        // if (hi < lo + CUTOFF - 1) {
        //     Insertion.sort(nums, lo, hi);
        //     return;
        // }

        // int m = medianOf3(nums, lo, lo + (hi - lo) / 2, hi);
        // swap(nums, m, lo);

        int j = partition(nums, lo, hi);
        sort(nums, lo, j - 1);
        sort(nums, j + 1, hi);
    }

    /** nums[lo..j-1] <= nums[j] <= nums[j+1..hi] */
    private static int partition(int[] nums, int lo, int hi) {
        int i = lo, j = hi + 1;
        int pivot = nums[lo];
        while (true) {
            while (nums[++i] < pivot) {
                if (i == hi)
                    break;
            }
            while (nums[--j] > pivot) {
                if (j == lo)
                    break;
            }
            if (i >= j) // check if pointers cross
                break;
            swap(nums, i, j);
        }
        swap(nums, lo, j);
        return j;
    }

    /** fisher-yates shuffle */
    private static void shuffle(int[] nums) {
        int n = nums.length;
        Random rand = new Random();
        for (int i = n - 1; i >= 0; i--) {
            int index = rand.nextInt(i + 1);
            swap(nums, index, i);
        }
    }

    private static void swap(int[] A, int i, int j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

/** Merge sort */
class MergeSort {
    public int[] sortArray(int[] nums) {
        mergesort(nums, 0, nums.length - 1);
        return nums;
    }
    
    private void mergesort(int[] nums, int lo, int hi) {
        if (hi - lo <= 0) 
            return;
        
        int mid = lo + (hi - lo) / 2;
        mergesort(nums, lo, mid);
        mergesort(nums, mid + 1, hi);
        merge(nums, lo, mid, hi);
    }
    
    private void merge(int[] nums, int lo, int mid, int hi) {
        int[] aux = new int[hi - lo + 1];
        int p1 = lo, p2 = mid + 1, i = 0;
        
        while (p1 <= mid && p2 <= hi) {
            if (nums[p1] < nums[p2]) {
                aux[i++] = nums[p1++];
            } else {
                aux[i++] = nums[p2++];
            }
        }
        
        while (p1 <= mid) 
            aux[i++] = nums[p1++];
        while (p2 <= hi) 
            aux[i++] = nums[p2++];
        
        for (int j = 0; j < aux.length; j++) {
            nums[j + lo] = aux[j];
        }
    }
}
