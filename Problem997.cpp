#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        vector<int> count(N + 1, 0);

        for (auto &t : trust)
        {
            count[t[0]]--;
            count[t[1]]++;
        }

        for (int i = 1; i <= N; i++)
        {
            if (count[i] == N - 1)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    int n = 3;
    vector<vector<int>> trust = {{1,3},{2,3},{3,1}};

    Solution sobj;
    cout<<"Judge is : "<<sobj.findJudge(n, trust);
    return 0;
}