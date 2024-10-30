//Given an integer array nums, return the length of the longest strictly increasing subsequence.


#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
        int lengthOfLIS(vector<int>& nums)
        {
            vector<int> temp;
            temp.assign(nums.size(),1);

            for(int i = 1;i < nums.size();i++)
            {
                for(int j = 0;j < i;j++)
                {
                    if(nums[i] > nums[j])
                    {
                        if(temp[j]+1 > temp[i])
                        {
                            temp[i] = temp[j]+1;
                        }
                    }
                }
            }

            int maxIndex = 0;

            for(int i = 0;i < temp.size();i++)
            {
                cout<<"\n"<<temp[i];
                if(temp[i] > temp[maxIndex])
                {
                    maxIndex = i;
                }
            }

            return temp[maxIndex];
        }

    private:
        int lengthOfLIS1(vector<int>& nums)
        {
            vector<int> temp;
            temp.push_back(nums[0]);

            int len = 1;

            for(int i = 1;i < nums.size();i++)
            {
                if(nums[i] > temp.back())
                {
                    temp.push_back(nums[i]);
                    len++;
                }
                else
                {
                    int index = binarySearch(temp,nums[i]);
                    temp[index] = nums[i];
                }
            }

            return len;
        }
        int binarySearch(const vector<int>&arr,int target)
        {
            int left = 0;
            int right = arr.size() - 1;

            while(left <= right)
            {
                int mid = (left + right)/ 2;

                if(arr[mid] == target)
                {
                    return mid;
                }
                else if(arr[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            return left;
        }
};


int main()
{
    Solution s;
    vector<int> arr = {0,1,0,3,2,3};

    int ret = s.lengthOfLIS(arr);
    cout<<"\nResult :: "<<ret;

    return 0;
}


//10,101        
//9,101
//2,5,7,101
//5,7,101
//3,7,101
//7,101
//18