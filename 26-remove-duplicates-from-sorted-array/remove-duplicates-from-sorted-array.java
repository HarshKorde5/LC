class Solution {
    public int removeDuplicates(int[] nums) {
        int start = 0, end = 1;
        int n = nums.length;

        while(end < n){

            if(nums[end] != nums[start]){
                nums[++start] = nums[end];
            }
            end++;
        }

        return ++start;
    }
}