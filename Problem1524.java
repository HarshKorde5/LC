class Solution {

    public int numOfSubarrays(int[] arr) {
        final int MOD = 1_000_000_007;
        int count = 0, prefixSum = 0;
        // evenCount starts as one since the initial sum (0) is even
        int oddCount = 0, evenCount = 1;

        for (int num : arr) {
            prefixSum += num;
            // If current prefix sum is even, add the number of odd subarrays
            if (prefixSum % 2 == 0) {
                count += oddCount;
                evenCount++;
            } else {
                // If current prefix sum is odd, add the number of even
                // subarrays
                count += evenCount;
                oddCount++;
            }

            count %= MOD; // To handle large results
        }

        return count;
    }
}

class Problem1524{

    public static void main(String arg[]){

        Solution s = new Solution();
        int nums[] = {1,2,3,4,5,6,7};
        System.out.println(s.numOfSubarrays(nums));
    }
}