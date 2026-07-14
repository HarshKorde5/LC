class Solution {
    public int pivotIndex(int[] nums) {
        int totalsum = Arrays.stream(nums).sum();
        int currsum = 0;
        for(int i = 0; i < nums.length; i++){
            if((totalsum - nums[i] - currsum) == currsum){
                return i;
            }

            currsum += nums[i];
        }

        return -1;
    }
}