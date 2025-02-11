/*
Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* removeOccurrences1(char* s, char* p) {
    const short n = strlen(s), m = strlen(p);
    char* ret = (char *)malloc(sizeof(char) * n + 1);

    int k = 0;
    const char end = p[m - 1];

    for(int i = 0;i < n;i++){

        ret[k++] = s[i];

        if(s[i] == end && k >= m){
            int j = 0;

            while(j < m && ret[k - m + j] == p[j]){
                j++;
            }

            if(j == m){
                k -= m;
            }
        }
    }


    ret[k] = '\0';
    return ret;

}


char* removeOccurrences(char* s, const char* part) {
    size_t lenPart = strlen(part);
    char* pos;

    while ((pos = strstr(s, part)) != NULL) {
        memmove(pos, pos + lenPart, strlen(pos + lenPart) + 1);
    }

    return s;
}

int main(){
    char str[] = {"daabcbaabcbc"};
    const char part[] = {"abc"};

    char * ret = removeOccurrences(str,part); 

    printf("%s\n",ret);
    return 0;
}