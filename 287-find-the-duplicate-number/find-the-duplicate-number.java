class Solution {
    public int findDuplicate(int[] nums) {
        int n = nums.length;

        int start = 1, end = n - 1;


        while(start < end){
            int mid = start + (end - start) / 2;
            int count = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] <= mid){
                    count++;
                }
            }

            if(count <= mid){
                start = mid + 1;
            }else{
                end = mid;
            }
        }


        return start;
    }
}
