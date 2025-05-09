/*

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string licenseKeyFormatting(string s, int k) {
            int count = 0;
            int n = s.length();
            string ans = "";
            for (int i = n - 1; i >= 0; i--) {
                if (s[i] != '-') {
                    ans.push_back(toupper(s[i]));
                    count++;
                    if (count == k) {
                        ans.push_back('-');
                        count = 0;
                    }
                }
            }
            if (ans.size() > 0 && ans.back() == '-') {
               ans.pop_back();
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
};

int main(){
    Solution s;
    string str = {"2-5g-3-J"};
    int k = 2;
    cout<<s.licenseKeyFormatting(str,k);
    return 0;
}