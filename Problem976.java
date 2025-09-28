/*
Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.
*/
import java.util.*;

class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        for(int i = nums.length - 3; i >= 0; i--){
            if(nums[i] + nums[i + 1] > nums[i + 2]){
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }
        return 0;
    }
}

class Problem976{
    public static void main(String[] args){
        Solution s = new Solution();

        int nums[] = {2,1,2};
        int result = s.largestPerimeter(nums);
        System.out.println("Perimeter : "+result);
    }
}