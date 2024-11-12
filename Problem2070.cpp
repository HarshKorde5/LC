
/*

You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively.

You are also given a 0-indexed integer array queries. For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal to queries[j]. If no such item exists, then the answer to this query is 0.

Return an array answer of the same length as queries where answer[j] is the answer to the jth query.


*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) 
    {
        vector<int> ans(queries.size());
        sort(items.begin(), items.end(),[](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        vector<vector<int>> queriesWithIndices(queries.size(), vector<int>(2));

        for (int i = 0; i < queries.size(); i++) 
        {
            queriesWithIndices[i][0] = queries[i];
            queriesWithIndices[i][1] = i;
        }

        sort(queriesWithIndices.begin(), queriesWithIndices.end(),[](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        int itemIndex = 0;
        int maxBeauty = 0;

        for (int i = 0; i < queries.size(); i++) 
        {
            int query = queriesWithIndices[i][0];
            int originalIndex = queriesWithIndices[i][1];

            while (itemIndex < items.size() && items[itemIndex][0] <= query) 
            {
                maxBeauty = max(maxBeauty, items[itemIndex][1]);
                itemIndex++;
            }

            ans[originalIndex] = maxBeauty;
        }
        return ans;
    }


    //TLE
    vector<int> maximumBeauty1(vector<vector<int>>& items, vector<int>& queries) 
    {
        vector<int> result = {};

        for(int i = 0;i < queries.size();i++)    
        {
            int maxBeauty = 0;
            
            for(int j = 0;j < items.size();j++)
            {
                if(items[j][0] <= queries[i])
                {
                    if(maxBeauty < items[j][1])
                    {
                        maxBeauty = items[j][1];
                    }
                }
            }

            result.push_back(maxBeauty);
        }

        return result;
    }
};



int main()
{
    Solution s;

    vector<vector<int>> items = {{1,2},{3,2},{2,4},{5,6},{3,5}};
    vector<int> queries = {1,2,3,4,5,6};

    vector<int> ret = s.maximumBeauty(items,queries);

    for(int i = 0;i < ret.size()-1;i++)
    {
        cout<<"\n"<<ret[i];
    }
    return 0;
}