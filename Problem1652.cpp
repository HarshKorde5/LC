
/*
You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

If k > 0, replace the ith number with the sum of the next k numbers.
If k < 0, replace the ith number with the sum of the previous k numbers.
If k == 0, replace the ith number with 0.
As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!


*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        int n = code.size();

        if(k == 0)    
        { 
            return vector<int> (n,0);
        }

        vector<int> res;

        for(int i = 0;i < n;i++)
        {
            int sum = 0;
            if(k < 0)
            {
                int j = 1;

                while(j <= -k)
                {
                    sum += code[(i-j+n)%n];
                    j++;
                }

            }
            else
            {
                int j = 1;

                while(j <= k)
                {           
                    sum += code[(i+j)%n];
                    j++;
                }

            }
            
            res.push_back(sum);

        }

        return res;
    }
};


int main()
{

    Solution s;

    vector<int> nums = {5,7,1,4};

    vector<int> res = s.decrypt(nums,3);

    for(int i = 0;i < nums.size();i++)
    {
        cout<<res[i]<<"\n";
    }

    return 0;
}