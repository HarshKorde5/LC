/*
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.
*/

import java.util.*;

class Solution {
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int result = 0;
        for (int i = 0; i < nums.length; i += 2) {
            result += nums[i];
        }
        return result;
    }
}

class Problem561{
    public static void main(String arg[]){

        Solution s = new Solution();
        int nums[] = {6,2,6,5,1,2};
        System.out.println(s.arrayPairSum(nums));
    }
}