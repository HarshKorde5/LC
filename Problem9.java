/*
Given an integer x, return true if x is a palindrome,and false otherwise.
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
*/

import java.util.*;

class Solution
{
    public boolean isPalindrome(int x)
    {

        if(x < 0)
        {
            return false;
        }

        int temp = x;
        int newno = 0;
        int no = 0;


        while(temp != 0)
        {
            no = temp % 10;
            newno = newno*10 + no;
            temp = temp/10;
        }

        if(x == newno)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

class Problem9
{
    public static void main(String arg[])
    {
        System.out.println("Enter number : ");
        Scanner sobj = new Scanner(System.in);
        int no = sobj.nextInt();

        Solution obj = new Solution();
        boolean bRet = obj.isPalindrome(no);
        if(bRet)
            System.out.println("Number is pallindrome");
        else
            System.out.println("Number is not Pallindrome");
    }
}