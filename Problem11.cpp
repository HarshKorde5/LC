/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    /////////////////////////////////////////////////////////////////////////////////
    //  Two Pointer Approach
    /////////////////////////////////////////////////////////////////////////////////

    int maxArea(vector<int>& height) 
    {
        const int n = height.size();
        int left = 0,right = n - 1;
        int max = 0;

        while(left < right)
        {
            int smallerHeight = height[left] < height[right] ? height[left] : height[right];
            int area = (right - left) * smallerHeight;

            max = area > max ? area : max;

            if(smallerHeight == height[left])
            {
                left++;
            }
            else    
            {
                right--;
            }
        }

        return max;
    }
};

int main()
{
    Solution s;

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout<<s.maxArea(height);

    return 0;
}