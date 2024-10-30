#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int longestSquareStreak(vector<int>& nums)
        {

            map<int,int> mp;
            sort(nums.begin(),nums.end());
            int res = -1;
            for(int num : nums)
            {
                int _sqrt = sqrt(num);
                if(_sqrt*_sqrt == num && mp.find(_sqrt) != mp.end())
                {
                    mp[num] = mp[_sqrt]+1;
                    res = max(res,mp[num]);
                }
                else
                {
                    mp[num] = 1;
                }
            }

            return res;
        }

};

int main()
{
    int n = sqrt(8);
    cout<<n<<"\n";
    Solution s;
    vector<int> arr = {4,3,6,16,8,2};
    int ret = s.longestSquareStreak(arr);
    cout<<ret;
}