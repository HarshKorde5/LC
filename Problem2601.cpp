/*
You are given a 0-indexed integer array nums of length n.

You can perform the following operation as many times as you want:

Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].
Return true if you can make nums a strictly increasing array using the above operation and false otherwise.

A strictly increasing array is an array whose each element is strictly greater than its preceding element.
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    bool primeSubOperation(vector<int>& nums) 
    {
        int max = *max_element(nums.begin(),nums.end());

        vector<int> sieve(max+1,1);

        sieve[1] = 0;

        for(int i = 2;i <= sqrt(max+1);i++)
        {
            if(sieve[i] == 1)
            {
                for(int j = i*i;j <= max;j += i) 
                {
                    sieve[j] = 0;
                }           
            }
        }


        int curr = 1;
        int i = 0;

        while(i < nums.size())
        {
            int diff = nums[i] - curr;

            if(diff < 0)
            {
                return 0;
            }

            if(sieve[diff] == 1 || diff == 0)
            {
                i++;
                curr++;
            }
            else
            {
                curr++;
            }
        }


        return 1;
    }

    bool primeSubOperation1(vector<int>& nums) 
    {
        int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
        
        int n = nums.size();
        int pn = sizeof(primes)/sizeof(primes[0]);
        bool flag = true;

        if(nums[n-1]!= 2) nums[n-1] = nums[n-1] - 2;

        for(int i = n-2;i >= 0;i--)
        {
            int p = 2;

            if(nums[i]-p < nums[i+1])
            {
                nums[i] = nums[i] - p;
            }
            else
            {
                p = getNextPrime(nums[i],nums[i+1],primes,pn);

                if(p == -1)
                {
                    flag = false;
                    break;
                }
                else
                {

                    nums[i] = nums[i] - p;
                }

            }

            if(nums[i] <= 0) flag = false; break;

        }

        return flag;
    }

    private :
        int getNextPrime(int n,int n1,int *primes,int pn)
        {
            int i =0;
            while(i < pn && primes[i] < n)
            {
                int p = primes[i];
                if(n - p < n1)
                {
                    return p;
                }
                i++;
            }
            return -1;
        }
};

int main()
{
    Solution s;
    vector<int> nums(998,2);
    cout<<s.primeSubOperation(nums);
    return 0;
}