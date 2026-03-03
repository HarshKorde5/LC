/*
Given two positive integers n and k, the binary string Sn is formed as follows:

S1 = "0"
Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

For example, the first four strings in the above sequence are:

S1 = "0"
S2 = "011"
S3 = "0111001"
S4 = "011100110110001"
Return the kth bit in Sn. It is guaranteed that k is valid for the given n.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char findKthBit(int n, int k)
    {
        string sequence = "0";

        for (int i = 1; i < n && k > sequence.length(); ++i)
        {
            sequence += '1';

            string temp = sequence;
            for (int j = temp.length() - 2; j >= 0; --j)
            {
                char invertedBit = (temp[j] == '1') ? '0' : '1';
                sequence += invertedBit;
            }
        }

        return sequence[k - 1];
    }
};

int main()
{

    Solution sobj;

    int n = 4, k = 3;

    cout << sobj.findKthBit(n, k) << endl;
    return 0;
}