#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        vector<vector<int>> result;

        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;

        for (int i = 0; i < arr.size() - 1; i++)
        {
            int diff = abs(arr[i] - arr[i + 1]);

            if (diff == minDiff)
            {
                result.push_back({arr[i], arr[i + 1]});
            }

            if (diff < minDiff)
            {
                minDiff = diff;
                result.clear();
                result.push_back({arr[i], arr[i + 1]});
            }
        }

        return result;
    }
};

int main()
{
    vector<int> arr = {3,8,-10,23,19,-4,-14,27};

    Solution sobj;
    vector<vector<int>> ret = sobj.minimumAbsDifference(arr);

    cout<<"Minimum difference pairs are : "<<endl;
    for(auto& p : ret){
        cout<<"{"<<p[0]<<","<<p[1]<<"}"<<endl;
    }
    return 0;
}