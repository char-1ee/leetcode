package Elementary;

class Solution {
    public int[] replaceElements(int[] arr) {
        int n = arr.length, temp, max = -1;
        for (int i = n - 1; i >= 0; i--) {
            temp = arr[i];
            arr[i] = max;
            max = Math.max(max, temp);
            // max = Math.max(arr[i], arr[i] = max);
        }

        // int n = arr.length;
        // for (int i = 0; i < n; i++){
        // int max = 0;
        // if (i == n - 1){
        // arr[i] = -1;
        // break;}
        // for (int j = i+1; j < n; j++){
        // if (arr[j] >= max) max = arr[j];
        // arr[i] = max;
        // }
        // }
        return arr;
    }
}