/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
*/

#include<stdio.h>

char* reverseWords(char* ptr) {
    /*
        traverse whole string until '/0'
        at each index check if char is ' '
        if not space push char to the stack
        if space occurs pop all char one by one and add to the result string
    */

    /*
        first pointer travels till occurence of space
        second pointer will point at previous character start
        once first pointer reaches the space it will stop,allocate a new end pointer swap all the chars between start and end,
        update start to the next index of space(i.e. our first pointer)
        continue
    */
    char *s = ptr;
    char *start = s;
    while(*s != '\0'){

        if(*s != ' ' && *s != '\0'){
            s++;
        }else{
            char *end = (s-1);
            while(start <= end){
                char temp = *start;
                *start = *end;
                *end = temp;
                start++;
                end--;
            }

            start = ++s;
        }

    }
    s--;
    while(start <= s){
        char temp = *start;
        *start = *s;
        *s = temp;
        start++;
        s--;
    }
    return ptr;
}

int main(){
    char s[] = {"Let's take LeetCode contest"};
    char *ret = reverseWords(s);
    printf("%s\n",ret);

    return 0;
}