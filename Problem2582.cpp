/*
There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.
Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ///////////////////////////////////////////////////////////////////////////////
    //  Brute Force Simulation
    ///////////////////////////////////////////////////////////////////////////////
    int passThePillow1(int n, int time) 
    {
        int currentPillowPosition = 1;
        int currentTime = 0;
        int direction = 1;

        while (currentTime < time) 
        {
            if (0 < currentPillowPosition + direction && currentPillowPosition + direction <= n)
            {
                currentPillowPosition += direction;
                currentTime++;
            } 
            else 
            {
                // Reverse the direction if the next position is out of bounds
                direction *= -1;
            }
        }
        return currentPillowPosition;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //  O(1) Maths
    ///////////////////////////////////////////////////////////////////////////////
    int passThePillow(int n, int time) 
    {
        int fullRounds = time / (n - 1);

        int extraTime = time % (n - 1);

        if(fullRounds % 2 == 0)
        {
            return extraTime + 1;
        }
        else
        {
            return n - extraTime;
        }
    }
};

int main()
{
    Solution s;

    cout<<s.passThePillow(4,5);
    
    return 0;
}