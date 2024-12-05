/*
You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:

The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.
*/


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canChange1(string start, string target) 
    {
        queue<pair<char,int>> squeue,tqueue;

        for(int i = 0;i < start.size();i++)
        {
            if(start[i] != '_')
            {
                squeue.push({start[i],i});
            }
            if(target[i] != '_')
            {
                tqueue.push({target[i],i});
            }
        }


        if(squeue.size() != tqueue.size())  return false;


        while(!squeue.empty())
        {
            auto [sch,sidx] = squeue.front();

            squeue.pop();

            auto [tch,tidx] = tqueue.front();

            tqueue.pop();

            if((sch != tch)||(sch == 'L' && sidx < tidx)||(sch == 'R' && sidx > tidx))
            {
                return false;
            }
        }

        return true;
    }

    bool canChange(string start, string target) 
    {
        int m = start.length();
        int n = target.length();

        int i = 0,j = 0;


        while(i < m || j < n)
        {
            while(i < m && start[i] == '_')     i++;

            while(j < n && target[j] == '_')    j++;

            if(i == m || j == n)
            {
                return i == m && j == m;
            }

            if((start[i] != target[j]) || (start[i] == 'L' && i < j) || (start[i] == 'R' && i > j))
            {
                return false;
            }


            i++;
            j++;

        }



        return true;
    }
};

int main()
{
    Solution s;

    string start("_L__R__R_");
    string target("L______RR");

    cout<<s.canChange(start,target);

    return 0;
}