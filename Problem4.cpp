//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

//The overall run time complexity should be O(log (m+n)).




#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        double ret = 0.0;

        int m = nums1.size();
        int n = nums2.size();

        vector<int> merged;

        int i = 0,j = 0;

        while(i < m && j < n)
        {
            if(nums1[i] < nums2[j])
            {
                merged.push_back(nums1[i]);
                i++;
            }
            else
            {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        while(i < m)
        {
            merged.push_back(nums1[i]);
            i++;
        }


        while(j < n)
        {
            merged.push_back(nums2[j]);
            j++;
        }
        
        if((m+n)%2 == 0)
        {
            ret = (double)merged[((m+n)/2)-1]+(double)merged[((m+n)/2)];
            ret = ret / 2;
        }
        else
        {
            ret = (double)merged[((m+n)/2)];
        }

        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};

    double ret = s.findMedianSortedArrays(nums1,nums2);

    cout<<"\nresult :: "<<ret;


    return 0;
}