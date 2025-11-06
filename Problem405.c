/*
Given a 32-bit integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.

All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.

Note: You are not allowed to use any built-in library method to directly solve this problem.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* toHex(int num) {
    if( num == 0){
        return "0";
    }

    char* ans  = (char* )malloc(9);
    if(!ans ) return NULL;

    unsigned int num1 = num;

    int index = 0;

    while(num1 ){
        int temp = num1 % 16;
        num1 /= 16;

        if(temp < 10){
            ans[index++] = '0' + temp;
        }else{
            ans[index++] = 'a' + (temp - 10);            
        }
    }


    ans[index] = '\0';
    int len = strlen(ans);
    for(int i = 0; i < len / 2; i++){
        char temp = ans[i];
        ans[i] = ans[len - i - 1];
        ans[len - i - 1] = temp;
    }

    return ans;
}

int main(){

    int num = -1;

    printf("%d -> %s\n",num,toHex(num));

    return 0;
}