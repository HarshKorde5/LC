
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]
*/

class Solution
{
    public int[] twoSum(int[] nums, int target)
    {
        int iret[] = new int[2];
        int i = 0,j = 0;

        for(i = 0;i < nums.length;i++)
        {
            for(j = i+1;j < nums.length;j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    iret[0] = i;
                    iret[1] = j;
                }
            }
        }
        return iret;
    }
}

class Problem1
{
    public static void main(String arg[])
    {
        int[] nums = {3,2,4};
        Solution sobj = new Solution();
        int[] ret = sobj.twoSum(nums,6);

        System.out.println(ret[0]);
        System.out.println(ret[1]);
    }
}