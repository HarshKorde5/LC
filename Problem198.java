class Solution{
    /* the order is: prev2, prev1, num  */
    public int rob(int[] nums) {
        if (nums.length == 0) return 0;
        int prev1 = 0;
        int prev2 = 0;
        for (int num : nums) {
            int tmp = prev1;
            prev1 = Math.max(prev2 + num, prev1);
            prev2 = tmp;
        }
        return prev1;
    }
}

class Problem198{
    public static void main(String arg[]){
        Solution s = new Solution();
        int nums[] = {2,7,9,3,1};
        System.out.println(s.rob(nums));
    }
}