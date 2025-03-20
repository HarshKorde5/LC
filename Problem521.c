/*
Given two strings a and b, return the length of the longest uncommon subsequence between a and b. If no such uncommon subsequence exists, return -1.

An uncommon subsequence between two strings is a string that is a subsequence of exactly one of them.
*/

#include<stdio.h>
#include<string.h>
#include<math.h>

int findLUSlength(char* a, char* b) {
    return ( !strcmp(a,b) ? -1 : fmax(strlen(a),strlen(b)));
}

int main(){
    char a[] = {"aba"};
    char b[] = {"cdc"};

    printf("%d\n",findLUSlength(a,b));
    return 0;
}