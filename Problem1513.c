// Given a binary string s, return the number of substrings with all characters 1's. 
// Since the answer may be too large, return it modulo 109 + 7.

#include<stdio.h>

int numSub(char* s) {
    const long long MOD = 1000000007LL;

    long long result = 0;
    int ones = 0;


    while(*s != '\0'){
        if(*s == '1'){
            ones++;
            result += ones;
        }else{
            ones = 0;
        }
        s++;
    }

    return result % MOD;
    
}

int main()
{
    char* str = "0110101100001111";

    printf("Total substrings of all ones are : %d\n",numSub(str));

    return 0;
}