#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int res = 0;
        unordered_set<char> setJ(jewels.begin(), jewels.end());
        for (char ch : stones)
        {
            if (setJ.count(ch))
            {
                res++;
            }
        }

        return res;
    }
};

int main()
{
    Solution sobj;
    string jewels = "aA";
    string stones = "aAAbbbb";

    cout<<"Number of jewels in stone are : "<<sobj.numJewelsInStones(jewels, stones)<<endl;

    return 0;
}