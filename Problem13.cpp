/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
*/




#include<iostream>
using namespace std;

class Solution
{
    public: 
        int romanToInt(char *s)
        {
            char *ptr = s;
            int sum = 0;

            while(*ptr != '\0')
            {
                switch(*ptr)
                {
                    case 'I':
                        if(*(ptr+1) == 'V')
                        {
                            sum = sum + 4;
                            ptr++;
                        }
                        else if(*(ptr+1) == 'X')
                        {
                            sum = sum + 9;
                            ptr++;
                        }
                        else
                        {
                            sum = sum+1;
                        }
                    break;

                    case 'V':
                        sum = sum+5;
                    break;

                    case 'X':
                        if(*(ptr+1) == 'L')
                        {
                            sum = sum+40;
                            ptr++;
                        }
                        else if(*(ptr+1) == 'C')
                        {
                            sum = sum+90;
                            ptr++;
                        }
                        else
                        {
                            sum = sum+10;
                        }

                    break;

                    case 'L':
                        sum = sum+50;
                    break;

                    case 'C':
                        if(*(ptr+1) == 'D')
                        {
                            sum = sum+400;
                            ptr++;
                        }
                        else if(*(ptr+1) == 'M')
                        {
                            sum = sum+900;
                            ptr++;
                        }
                        else
                        {
                            sum = sum+100;
                        }
                    break;

                    case 'D':
                        sum = sum+500;
                    break;

                    case 'M':
                        sum = sum+1000;
                    break;

                    default:
                        cout<<"Wrong character\n";
                    break;
                }
                ptr++;
            }
            return sum;
        }
};

int main()
{
    char arr[20] = {"IV"};
    Solution sobj;
    int iret = sobj.romanToInt(arr);
    cout<<"Converted number is : "<<iret<<"\n";

    return 0;
}






