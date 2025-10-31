/*

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> count;
        for(int x : nums){
            count[x]++;
            if(count[x] == 2){
                res.push_back(x);
            }

        }

        return res;
    }
};


int main(){
    Solution sobj;

    vector<int> nums = {7,1,5,4,3,4,6,0,9,5,8,2};
    vector<int> ret = sobj.getSneakyNumbers(nums);

    cout<<"The two sneaky numbers are : "<<ret[0]<<" and "<<ret[1]<<endl;
    return 0;
}