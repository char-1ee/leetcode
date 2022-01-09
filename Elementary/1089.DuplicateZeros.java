package Elementary;

class Solution {
  // Two pointers with extra memory space
  public void duplicateZeros1(int[] arr) {
    int n = arr.length;
    int[] res = arr.clone();
    for (int i = 0, j = 0; i < n; i++, j++) {
      arr[i] = res[j];
      if (arr[i] == 0 && i < n - 1) {
        arr[++i] = 0;
      }
    }
  }

  // Two pointers with no extra space
  // Links:
  // https://leetcode.com/problems/duplicate-zeros/discuss/312743/JavaC%2B%2B-O(n)-or-O(1)
  public void duplicateZeros2(int[] a) {
    int i = 0, sh = 0;
    for (i = 0; sh + i < a.length; ++i)
      sh += a[i] == 0 ? 1 : 0;
    // sh = Collections.frequency(Array.asList(arr), 0);
    for (i = i - 1; sh > 0; --i) {
      if (i + sh < a.length)
        a[i + sh] = a[i];
      if (a[i] == 0)
        a[i + --sh] = a[i];
    }
  }

}
