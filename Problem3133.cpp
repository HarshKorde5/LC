#include<iostream>
using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        while(--n)
        {
            result = (result + 1) | x;
        }

        return result;
    }
};

int main()
{
    Solution s;
    cout<<s.minEnd(3,4);
    return 0;
}