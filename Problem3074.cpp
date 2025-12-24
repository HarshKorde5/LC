/*
You are given an array apple of size n and an array capacity of size m.

There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.

Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.

Note that, apples from the same pack can be distributed into different boxes.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        int appleSum = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());

        int need = 0;

        while (appleSum > 0)
        {
            appleSum -= capacity[need];
            need += 1;
        }

        return need;
    }
};

int main()
{
    Solution sobj;
    vector<int> apple = {1,3,2};
    vector<int> capacity = {4,3,1,5,2};
    cout<<"Minimum boxes needed are : "<<sobj.minimumBoxes(apple, capacity)<<endl;

    return 0;
}