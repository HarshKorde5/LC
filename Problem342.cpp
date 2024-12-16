
/*
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        // Iterate through powers of 4 from 4^0 to 4^15
        for (int i = 0; i <= 15; i++) {
            int powerOfFour = pow(4, i);
            
            // If we find a power of four equal to 'n', return true
            if (powerOfFour == n)
                return true;
            
            // If the current power of four is greater than 'n', there's no need to continue
            if (powerOfFour > n)
                return false;
        }
        
        // 'n' is not a power of four
        return false;
    }
};

int main()
{
    Solution s;

    cout<<s.isPowerOfFour(16);

    return 0;
}