
/*
You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result;
        
        int pl = potions.size();
        int sl = spells.size();

        sort(potions.begin(), potions.end());
        

        for(int i = 0; i < sl; i++){

            int start = 0, end = pl - 1;
            int idx = pl;   // assume none of potions satisfies

            while(start <= end){
                int mid = (start + end) / 2;
                long long product = 1LL * potions[mid] * spells[i];

                if (product >= success){
                    idx = mid;  // mid is valid potion number
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }

            
                result.push_back(pl - idx);            
        }

        return result;
    }

    //TLE
    vector<int> successfulPairs_1(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result;

        for(long long spell : spells){
            int count = 0;
            for(long long potion : potions){
                if(potion*spell >= success){
                    count++;
                }
            }

            result.push_back(count);
        }

        return result;
    }
};


int main(){
    Solution sobj;

    vector<int> spells = {5,1,3};
    vector<int> potions = {1,2,3,4,5};

    int success = 7;

    vector<int> result = sobj.successfulPairs(spells, potions, success);

    for(int n : result){

        cout<<n<<endl;
    }

    return 0;
}