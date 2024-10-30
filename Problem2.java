/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/

import java.util.*;

class Node
{
    public int val;
    public Node next;

    Node(int no)
    {
        this.val = no;
        this.next = null;
    }
}

class Solution
{
    public Node ans;

    Solution()
    {
        this.ans = null;
    }
    
    public int generateCarry(int val)
    {
        return val/10;
    }

    public void finalAns(int val)
    {
        Node newn = new Node(val);
        if(this.ans == null)
        {
            this.ans = newn;
        }
        else
        {
            Node temp = this.ans;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
    }

    public void Display()
    {
        Node temp = ans;
        while(temp != null)
        {
            System.out.print(temp.val);
            temp = temp.next;
        }
    }

    public void addTwoNumbers(Node temp1, Node temp2,int carry)
    {
        int sum = 0;
        boolean cflag = false;

        if((temp1 == null)&&(temp2 != null))       //l1 is small
        {
            sum = 0;
            sum = temp2.val + carry;
            if(sum >= 10)
            {
                cflag = true;
                carry = this.generateCarry(sum);
                sum = sum % 10;
            }
            this.finalAns(sum);
            if((temp2.next == null)&&(cflag == true))
                this.finalAns(carry);
            
            if(cflag)
                this.addTwoNumbers(temp1,temp2.next,carry);
            else
                this.addTwoNumbers(temp1,temp2.next,0);
        }
        else if((temp1 != null)&&(temp2 == null))       //l2 is small
        {
            sum = 0;
            sum = temp1.val + carry;
            if(sum >= 10)
            {
                cflag = true;

                carry = this.generateCarry(sum);
                sum = sum % 10;
            }
            this.finalAns(sum);
            if((temp1.next == null)&&(cflag == true))
                this.finalAns(carry);


            if(cflag)
                this.addTwoNumbers(temp1.next,temp2,carry);
            else
                this.addTwoNumbers(temp1.next,temp2,0);

        }
        else if((temp1 != null)&&(temp2 != null))         //both ll are equal
        {
            sum = 0;

            sum = temp1.val + temp2.val + carry;
            if(sum >= 10)
            {
                cflag = true;

                carry = this.generateCarry(sum);
                sum = sum % 10;
            }
            this.finalAns(sum);
            if((temp1.next == null)&&(cflag == true))
                this.finalAns(carry);

            this.addTwoNumbers(temp1.next,temp2.next,carry);
        }
    }
}

class Problem2
{
    public static void main(String arg[])
    {
        Node list1 = null;
        Node list2 = null;
        
        Scanner sobj = new Scanner(System.in);
        
        char yn = 'Y';

        do
        {
            System.out.println("Enter 1st number in reverse order : ");
            int iNo = sobj.nextInt();

            Node newn = new Node(iNo);
            if(list1 == null)
            {
                list1 = newn;
            }
            else
            {
                Node temp = list1;
                while(temp.next != null)
                {
                    temp = temp.next;
                }
                temp.next = newn;
            }

            System.out.println("Want to enter digit? : Y/N");
            yn = sobj.next().charAt(0);

        }while(yn == 'Y');
        

        do
        {
            System.out.println("Enter 2nd number in reverse order : ");
            int iNo = sobj.nextInt();

            Node newn = new Node(iNo);
            if(list2 == null)
            {
                list2 = newn;
            }
            else
            {
                Node temp = list2;
                while(temp.next != null)
                {
                    temp = temp.next;
                }
                temp.next = newn;
            }

            System.out.println("Want to enter digit? : Y/N");
            yn = sobj.next().charAt(0);

        }while(yn == 'Y');


        Solution sol = new Solution();
        sol.addTwoNumbers(list1,list2,0);

        sol.Display();

    }

}