
class Solution {
    public int maxSumDivThree(int[] nums) {
        int[] dp = new int[3];

        for(int x : nums){
            int[] prev = dp.clone();


            for(int y : prev){
                int currSum = x + y;
                int rem = currSum % 3;

                dp[rem] = Math.max(dp[rem], currSum);
            }
        }

        return dp[0];
    }
}

class Problem1262{
    public static void main(String[] args){

        Solution sobj = new Solution();
        int[] nums = {3, 6, 5, 1, 8};
        
        int ret = sobj.maxSumDivThree(nums);

        System.out.println("Max sum divisible by 3 is "+ret);
    }
}