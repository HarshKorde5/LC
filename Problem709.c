/*
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.
*/

#include<stdio.h>
#include<string.h>
char* toLowerCase(char* s) {
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
    }
    return s;
}

int main(){
    char str[20] = "LOVELY";

    printf("%s",toLowerCase(str));

    return 0;
}