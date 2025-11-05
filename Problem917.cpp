/*
Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.
*/


#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters_1(string s) {
        
        int n = s.length();
        string res(n,' ');
        int left = 0, right = n - 1;

        while(left <= right){
            if(!isalpha(s[left])){
                res[left] = s[left];
                left++;
            }else if(!isalpha(s[right])){
                res[right] = s[right];
                right--;
            }else{
                res[left] = s[right];
                res[right] = s[left];
                left++;
                right--;
            }

        }

        return res;
    }

    string reverseOnlyLetters(string s) {
         int start = 0, end = s.size() - 1;
        while (start < end) {
            if (isalpha(s[start]) && isalpha(s[end])) {
                swap(s[start], s[end]);
                start++;
                end--;
            } else if (!isalpha(s[start])) {
                start++;
            } else {
                end--;
            }
        }
        return s;
    }
};

int main(){

    string s = "Test1ng-Leet=code-Q!";

    cout<<"String before operations : "<<s<<endl;

    Solution sobj;
    string ret = sobj.reverseOnlyLetters(s);

    cout<<"String after operations : "<<ret<<endl;

    return 0;
}