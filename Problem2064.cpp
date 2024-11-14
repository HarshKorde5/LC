
/*
You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.

You need to distribute all products to the retail stores following these rules:

A store can only be given at most one product type but can be given any amount of it.
After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.
Return the minimum possible x.

*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) 
    {   

        int start = 1,end = *max_element(quantities.begin(),quantities.end());

        int ans = end;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            int retailCount = productPerRetailer(mid,quantities);

            if(retailCount <= n)
            {
                ans = mid;
                end = mid - 1;
            }
            else 
            {
                start = mid + 1;
            }
        }

        return ans;
    }
private:
    int productPerRetailer(int mid,vector<int>& quantities)
    {
        int retailCount = 0;

        for(int i = 0;i < quantities.size();i++)
        {
            if(quantities[i] % mid)
            {
                retailCount += (quantities[i]/mid)+1;
            }
            else
            {
                retailCount += quantities[i]/mid;
            }
        }


        return retailCount;
    }
};


int main()
{

    Solution s;
    vector<int> quantities = {11,6};
    cout<<s.minimizedMaximum(6,quantities);
    return 0;
}