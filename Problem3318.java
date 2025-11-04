/* 
 You are given an array nums of n integers and two integers k and x.

The x-sum of an array is calculated by the following procedure:

Count the occurrences of all elements in the array.
Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
Calculate the sum of the resulting array.
Note that if an array has less than x distinct elements, its x-sum is the sum of the array.

Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].

 
*/

class Solution {
    public int[] findXSum(int[] nums, int k, int x) {
        int[] result = new int[nums.length - k + 1];

        for (int i = 0; i < result.length; i++) {
            int left = i, right = i + k - 1;
            result[i] = findXSumofSubArray(nums, left, right, x);
        }

        return result;
    }

    private int findXSumofSubArray(int[] nums, int left, int right, int x) {
        int sum = 0, distinctCount = 0;
        int[] freq = new int[51]; 

        for (int i = left; i <= right; i++) {
            sum += nums[i];
            if (freq[nums[i]] == 0) {
                distinctCount++;
            }
            freq[nums[i]]++;
        }

        if (distinctCount < x) {
            return sum;
        }

        sum = 0;
        for (int pick = 0; pick < x; pick++) {
            int bestFreq = -1;
            int bestVal = -1;

            for (int val = 50; val >= 1; val--) {
                if (freq[val] > bestFreq) {
                    bestFreq = freq[val];
                    bestVal = val;
                }
            }

            if (bestVal != -1) {
                sum += bestVal * bestFreq;
                freq[bestVal] = 0;
            }
        }
        
        return sum;
    }
}

class Problem3318{
    public static void main(String arg[]){

        int[] nums = {1,1,2,2,3,4,2,3};
        int k = 6;
        int x = 2;
        Solution sobj = new Solution();
        int[] ret = sobj.findXSum(nums, k, x);

        System.out.println("Result array is : ");
        for(int i : ret){
            System.out.println(i);            
        }
    }
}