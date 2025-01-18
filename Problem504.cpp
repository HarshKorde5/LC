/*
Given an integer num, return a string of its base 7 representation.
*/

#include<iostream>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        int nn=0,mul=1;
        while(num!=0)
        {
            nn+=mul*(num%7);
            num/=7;
            mul*=10;
        }
        return to_string(nn);
    }
};

int main(){

    Solution s;
    cout<<s.convertToBase7(100);
    return 0;
}