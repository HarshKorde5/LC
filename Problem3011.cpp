/*

You are given a 0-indexed array of positive integers nums.

In one operation, you can swap any two adjacent elements if they have the same number of 
set bits
. You are allowed to do this operation any number of times (including zero).

Return true if you can sort the array, else return false.



*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        bool canSortArray(vector<int>& nums) 
        {
            int n = nums.size();

            int prevMax = 0,currentMin = 0,currentMax = 0;
            int prevPopCount = 0,currentPopCount = 0;

            for(int no : nums)
            {
                if(currentPopCount = __builtin_popcount(no);prevPopCount == currentPopCount)
                {
                    currentMin = min(currentMin,no);
                    currentMax = max(currentMax,no);
                }
                else if(currentMin < prevMax)
                {
                    return false;
                }
                else
                {
                    prevMax = currentMax;
                    currentMin = currentMax = no;
                    prevPopCount = currentPopCount;
                }
            }

            return currentMin >= prevMax;
        }

        bool canSortArray1(vector<int>& nums) 
        {
            vector<vector<int>> groups;

            vector<int> temp;
            temp.push_back(nums[0]);

            for(int i = 1;i <= nums.size();i++)
            {
                if(__builtin_popcount(temp.back()) == __builtin_popcount(nums[i]))
                {
                    temp.push_back(nums[i]);
                }
                else
                {
                    groups.push_back(temp);
                    temp.clear();
                    temp.push_back(nums[i]);
                }
                
            }


            for(int i = 0;i < groups.size();i++)
            {
                for(int j = 0;j < groups[i].size();j++)
                {
                    cout<<"\t"<<groups[i][j];
                }
                cout<<"\n";
            }

            bool flag = true;
            for(int i = 1;i < groups.size();i++)
            {
                if(*max_element(groups[i-1].begin(),groups[i-1].end()) > *min_element(groups[i].begin(),groups[i].end()))
                {
                    flag = false;
                    break;
                }
            }

            return flag;
        }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2};

    cout<<s.canSortArray(nums);



    // cout<<"\n12 :: "<<__builtin_popcount(12);

    return 0;
}