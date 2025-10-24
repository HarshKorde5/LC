/*
An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.

Given an integer n, return the smallest numerically balanced number strictly greater than n.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isBalance(int x){
        vector<int> count(10);

        while(x > 0){
            count[x % 10]++;
            x /= 10;
        }

        for(int d = 0; d < 10; d++){
            if(count[d] > 0 && count[d] != d){
                return false;
            }
        }

        return true;
    }

    int nextBeautifulNumber(int n) {
        for(int i = n + 1; i <= 1224444; i++){
            if(isBalance(i)){
                return i;
            }
        }

        return -1;
    }
};

int main(){

    int n = 3000;

    Solution sobj;

    cout<<"Next beautiful number to "<<n<<" is : "<<sobj.nextBeautifulNumber(n)<<endl;
    return 0;
}