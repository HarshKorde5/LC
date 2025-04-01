/*
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string addStrings(string num1,string num2) {
            int i = num1.size() - 1, j = num2.size() - 1;
            int carry = 0;
            string result;
    
            while (i >= 0 || j >= 0 || carry) {
                int digit1 = (i >= 0) ? num1[i] - '0' : 0;
                int digit2 = (j >= 0) ? num2[j] - '0' : 0;
    
                int total = digit1 + digit2 + carry;
                carry = total / 10;
    
                result.push_back((total % 10) + '0');
    
                --i;
                --j;
            }
    
            reverse(result.begin(), result.end());
            return result;
        }
};


int main(){
    Solution s;
    string num1 = {"11"};
    string num2 = {"123"};

    cout<<s.addStrings(num1,num2);
    return 0;
}