/*
You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.

You are also given an integer k, which is the desired number of consecutive black blocks.

In one operation, you can recolor a white block such that it becomes a black block.

Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int left = 0, numWhites = 0, numRecolors = INT_MAX;
    
            // Move right pointer
            for (int right = 0; right < blocks.size(); right++) {
                // Increment numWhites if block at right pointer is white
                if (blocks[right] == 'W') {
                    numWhites++;
                }
    
                // k consecutive elements are found
                if (right - left + 1 == k) {
                    // Update minimum
                    numRecolors = min(numRecolors, numWhites);
    
                    // Decrement numWhites if block at left pointer is white
                    if (blocks[left] == 'W') numWhites--;
    
                    // Move left pointer
                    left++;
                }
            }
            return numRecolors;
        }
};

int main(){

    Solution s;
    string str = {"WBBWWBBWBW"};
    cout<<s.minimumRecolors(str,7);

    return 0;
}
