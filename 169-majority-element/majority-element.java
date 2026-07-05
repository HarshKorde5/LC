class Solution {
    public int majorityElement(int[] nums) {
        int val = 0;
        int freq = 0;
        for(int num : nums){
            if(freq == 0){
                val = num;
            }
            freq += (num == val) ? 1 : -1;
        }

        return val;
    }
}