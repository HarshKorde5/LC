/*
You are given an array nums consisting of positive integers.

Starting with score = 0, apply the following algorithm:

Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
Add the value of the chosen integer to score.
Mark the chosen element and its two adjacent elements if they exist.
Repeat until all the array elements are marked.
Return the score you get after applying the above algorithm.

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    ///////////////////////////////////////////////////////
    //  Brute Force => TLE
    ///////////////////////////////////////////////////////
    int getMinIdx(vector<int>& nums)
    {
        int min = INT_MAX;
        int minIdx = -1;
        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i] != -1)
            {
                if(nums[i] < min)
                {
                    minIdx = i;
                    min = nums[i];
                }
            }
        }

        return minIdx;
    }
    
    long long findScore1(vector<int>& nums) 
    {    
        if(nums.size() == 1)    return nums[0];
        long long sum = 0;
        int idx = 0;

        while(1)
        {
            idx = getMinIdx(nums);    
            if(idx == -1) break;

            sum += nums[idx];
            nums[idx] = -1;
            
            if(idx == 0) 
            {
                nums[idx+1] = -1;
            }
            else if(idx == nums.size()-1) 
            {
                nums[idx-1] = -1;
            }
            else 
            {
                nums[idx-1] = -1;
                nums[idx+1] = -1;
            }        
        }
        return sum;
    }

    //////////////////////////////////////////////////////
    //  Brute Force 2 => storing used indexed in a set
    //////////////////////////////////////////////////////

    long long findScore2(vector<int>& nums)
    {
        int n = nums.size();

        vector<vector<int>> indexed(n,vector<int>(2));

        for(int i = 0;i < n;i++)
        {
            indexed[i][0] = nums[i];
            indexed[i][1] = i;
        }

        sort(indexed.begin(),indexed.end());

        long long score = 0;

        set<int> used;

        for(int i = 0;i < n;i++)
        {
            int value = indexed[i][0];
            int idx = indexed[i][1];
            
            if(used.find(idx)!=used.end())
            {
                continue;
            }

            score += value;
            used.insert(idx);

            if(idx - 1 >= 0)
            {
                used.insert(idx - 1);
            }

            if(idx + 1 < n)
            {
                used.insert(idx + 1);
            }
        }

        return score;
    }


    //////////////////////////////////////////////////////
    //  Min Heap
    //////////////////////////////////////////////////////

    long long findScore3(vector<int>& nums)
    {
        long long score = 0;
        int n = nums.size();

        vector<bool> marked(n);

        auto cmp = [](pair<int,int>& p1,pair<int,int>& p2)
        {
            if(p1.first != p2.first)
            {
                return p1.first > p2.first;
            }

            return p1.second > p2.second;
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> heap(cmp);

        for(int i = 0;i < n;i++)
        {
            heap.push(make_pair(nums[i],i));
        }

        while(!heap.empty())
        {
            pair<int,int> element = heap.top();

            heap.pop();

            int number = element.first;
            int index = element.second;

            if(!marked[index])
            {
                score += number;
                marked[index] = true;

                if(index - 1 >= 0)
                {
                    marked[index - 1] = true;
                }

                if(index + 1 < n)
                {
                    marked[index + 1] = true;
                }
            }


        }

        return score;
    }

    /////////////////////////////////////////////////////
    //  Stack
    /////////////////////////////////////////////////////
    long long findScore(vector<int>& nums)
    {
        long long score = 0;
        int n = nums.size();
        deque<int> q;

        for(int i = 0;i < n;i++)
        {

            //If queue is not empty and the current number is greater than or equal to last element in the queue
            if(!q.empty() && nums[i] >= q.back())
            {
                bool skip = false;

                while(!q.empty())
                {
                    int add = q.back();

                    q.pop_back();

                    if(!skip)
                    {
                        score += add;
                    }

                    skip = !skip;
                }
                continue;
            }

            q.push_back(nums[i]);

        }

        //final processing of remaining elements in the queue;

        bool skip = false;

        while(!q.empty())
        {
            int add = q.back();

            q.pop_back();

            if(!skip)
            {
                score += add;
            }
            skip = !skip;
        }

        return score;
    }

};


int main()
{
    vector<int> nums = {2,1,3,4,5,2};

    Solution s;
    cout<<s.findScore(nums);

    return 0;
}