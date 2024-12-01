/*
Given an array arr of integers, check if there exist two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]

*/


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        unordered_set<int> seen;

        for(int num : arr)
        {
            if(seen.count(2*num) || (num % 2 == 0 && seen.count(num/2)))
            {
                return true;
            }

            seen.insert(num);
        }

        return false;
    }

    bool checkIfExist2(vector<int>& arr) 
    {
        unordered_map<int,int> map;

        for(int i : arr)
        {
            map[i]++;
        }


        for(int i : arr)
        {
            if(i != 0 && map.find(i*2) != map.end())
            {
                return true;
            }


            if(i == 0 && map[i] > 1)
            {
                return true;
            }
        }


        return false;
    }

    bool checkIfExist1(vector<int>& arr) 
    {
        int n = arr.size();

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(i != j && arr[i] == 2 * arr[j])
                {
                    return true;
                }
            }
        }

        return false;
    }
};


int main()
{
    Solution s;

    vector<int> arr = {10,2,5,3};

    cout<<s.checkIfExist(arr);

    return 0;
}