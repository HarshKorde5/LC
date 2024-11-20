/*
You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.

Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) 
    {
        int n = s.size();

        int left = 0,right = 0;

        int ans = n;

        int a = 0,b = 0,c = 0;

        int totalA = 0,totalB = 0,totalC = 0;

        for(char ch : s)
        {
            if(ch == 'a')   totalA++;
            else if(ch == 'b')  totalB++;
            else if(ch == 'c')  totalC++;
        }

        if(totalA < k || totalB < k || totalC < k)
        {
            return -1;
        }


        while(right < n)
        {
            if(s[right] == 'a')     a++;
            if(s[right] == 'b')    b++;
            if(s[right] == 'c')    c++;

            right++;


            while(a > totalA - k || b > totalB - k || c > totalC - k)
            {
                if(s[left] == 'a')      a--;
                if(s[left] == 'b')      b--;
                if(s[left] == 'c')      c--;
                
                left++;
            }


            ans = min(ans,n-(right - left));
        }

        return ans;
    }
};


int main()
{

    Solution s;

    string str("aabaaaacaabc");

    cout<<s.takeCharacters(str,2);


    return 0;
}