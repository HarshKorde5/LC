#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {

        int val = 0;

        for(auto& opn : operations){
            if(opn[1] == '+'){
                val++;
            }else{
                val--;
            }
        }

        return val;
    }
};

int main(){

    vector<string> operations = {"X--", "++X", "--X", "--X"};

    Solution sobj;

    cout<<"Output of operations is : "<<sobj.finalValueAfterOperations(operations)<<endl;
    
    return 0;
}