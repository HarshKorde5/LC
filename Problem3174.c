
/*
You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.
*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

char* clearDigits(char* s) {
    int n = strlen(s);
    int k = -1;
    char* ret = (char*)malloc(sizeof(char)*n+1);

    bool isDigit(char ch){
        return (ch >= '0' && ch <= '9');
    }

    bool isEmpty(){
        return (k == -1);
    }

    for(int i = 0;i < n;i++){
        if(isDigit(s[i]) && !isEmpty()){
            k--;
        }else{
            ret[++k] = s[i];
        }
    }

    ret[++k] = 0;
    return ret;
}


int main(){

    char str[] = {"abc0123jkl89m"};
    char *ret = clearDigits(str);
    printf("%s",ret);
    free(ret);
    return 0;
}