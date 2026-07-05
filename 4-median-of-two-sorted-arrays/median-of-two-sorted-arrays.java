class Solution {
    public double findMedianSortedArrays(int[] A, int[] B) {
        int m = A.length, n = B.length;

        int i = 0, j = 0;
        int prev = 0, curr = 0;

        for (int k = 0; k <= (m + n) / 2; k++) {
            prev = curr;

            if (j == n || (i < m && A[i] <= B[j])) {
                curr = A[i++];
            } else {
                curr = B[j++];
            }
        }

        return ((m + n) % 2 == 1) ? curr : (prev + curr) / 2.0;
    }
}